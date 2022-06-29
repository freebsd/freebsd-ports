--- sandbox/policy/openbsd/sandbox_openbsd.cc.orig	2022-06-19 00:45:01 UTC
+++ sandbox/policy/openbsd/sandbox_openbsd.cc
@@ -0,0 +1,407 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+
+#include <dirent.h>
+#include <fcntl.h>
+#include <stdint.h>
+#include <sys/resource.h>
+#include <sys/stat.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <unistd.h>
+#include <util.h>
+
+#include <limits>
+#include <memory>
+#include <string>
+#include <vector>
+
+#include "base/bind.h"
+#include "base/callback_helpers.h"
+#include "base/command_line.h"
+#include "base/debug/stack_trace.h"
+#include "base/feature_list.h"
+#include "base/files/file_path.h"
+#include "base/files/file_util.h"
+#include "base/files/scoped_file.h"
+#include "base/logging.h"
+#include "base/memory/singleton.h"
+#include "base/path_service.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/system/sys_info.h"
+#include "base/time/time.h"
+#include "build/build_config.h"
+#include "sandbox/constants.h"
+#include "sandbox/linux/services/credentials.h"
+#include "sandbox/linux/services/namespace_sandbox.h"
+#include "sandbox/linux/services/proc_util.h"
+#include "sandbox/linux/services/resource_limits.h"
+#include "sandbox/linux/services/thread_helpers.h"
+#include "sandbox/linux/syscall_broker/broker_command.h"
+#include "sandbox/linux/syscall_broker/broker_process.h"
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/policy/sandbox_type.h"
+#include "sandbox/policy/mojom/sandbox.mojom.h"
+#include "sandbox/policy/switches.h"
+#include "sandbox/sandbox_buildflags.h" 
+
+#if BUILDFLAG(USING_SANITIZER)
+#include <sanitizer/common_interface_defs.h>
+#endif
+
+#if defined(USE_NSS_CERTS)
+#include "crypto/nss_util.h"
+#endif
+
+#include "third_party/boringssl/src/include/openssl/crypto.h"
+
+#include "ui/gfx/x/connection.h"
+#include "ui/gfx/font_util.h"
+
+#include <X11/Xlib.h>
+
+#define MAXTOKENS	3
+
+#define _UNVEIL_MAIN		"/etc/chromium/unveil.main";
+#define _UNVEIL_RENDERER	"/etc/chromium/unveil.renderer";
+#define _UNVEIL_GPU		"/etc/chromium/unveil.gpu";
+#define _UNVEIL_PLUGIN		"/etc/chromium/unveil.plugin";
+#define _UNVEIL_UTILITY		"/etc/chromium/unveil.utility";
+#define _UNVEIL_UTILITY_NETWORK	"/etc/chromium/unveil.utility_network";
+#define _UNVEIL_UTILITY_AUDIO	"/etc/chromium/unveil.utility_audio";
+#define _UNVEIL_UTILITY_VIDEO	"/etc/chromium/unveil.utility_video";
+
+namespace sandbox {
+namespace policy {
+
+SandboxLinux::SandboxLinux()
+    : unveil_initialized_(false),
+      sandbox_status_flags_(kInvalid),
+      pre_initialized_(false),
+      initialize_sandbox_ran_(false),
+      broker_process_(nullptr) {
+}
+
+SandboxLinux::~SandboxLinux() {
+  if (pre_initialized_) {
+    CHECK(initialize_sandbox_ran_);
+  }
+}
+
+SandboxLinux* SandboxLinux::GetInstance() {
+  SandboxLinux* instance = base::Singleton<SandboxLinux>::get();
+  CHECK(instance);
+  return instance;
+}
+
+void SandboxLinux::PreinitializeSandbox(sandbox::mojom::Sandbox sandbox_type) {
+  CHECK(!pre_initialized_);
+#if BUILDFLAG(USING_SANITIZER)
+  // Sanitizers need to open some resources before the sandbox is enabled.
+  // This should not fork, not launch threads, not open a directory.
+  __sanitizer_sandbox_on_notify(sanitizer_args());
+  sanitizer_args_.reset();
+#endif
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  const std::string process_type =
+      command_line->GetSwitchValueASCII(switches::kProcessType);
+
+  base::SysInfo::AmountOfPhysicalMemory();
+  base::SysInfo::NumberOfProcessors();
+  base::SysInfo::CPUModelName();
+
+#if defined(USE_NSS_CERTS)
+  // The main process has to initialize the ~/.pki dir which won't work
+  // after unveil(2).
+  if (process_type.empty())
+    crypto::EnsureNSSInit();
+#endif
+
+  if (process_type.empty())
+    CRYPTO_pre_sandbox_init();
+
+  // cache the XErrorDB by forcing a read on it
+  {
+    auto* connection = x11::Connection::Get();
+    auto* display = connection->GetXlibDisplay().display();
+
+    char buf[1];
+    XGetErrorDatabaseText(display, "XProtoError", "0", "",  buf, std::size(buf));
+  }
+
+  if (process_type.empty()) {
+    base::FilePath cache_directory, local_directory;
+
+    base::PathService::Get(base::DIR_CACHE, &cache_directory);
+    base::PathService::Get(base::DIR_HOME, &local_directory);   
+
+    cache_directory = cache_directory.AppendASCII("chromium");
+    local_directory = local_directory.AppendASCII(".local").AppendASCII("share").AppendASCII("applications");
+
+    if (!base::CreateDirectory(cache_directory)) {
+      LOG(ERROR) << "Failed to create " << cache_directory.value() << " directory.";
+    }
+
+    if (!base::CreateDirectory(local_directory)) {
+      LOG(ERROR) << "Failed to create " << local_directory.value() << " directory.";
+    }
+  }
+
+  if (process_type == switches::kRendererProcess)
+    gfx::InitializeFonts();
+
+  if (!command_line->HasSwitch(switches::kDisableUnveil))
+    SetUnveil(process_type, sandbox_type);
+
+  pre_initialized_ = true;
+}
+
+bool SandboxLinux::SetPledge(const char *pstring, const char *ppath) {
+  FILE *fp;
+  char *s = NULL;
+  size_t len = 0;
+  ssize_t read;
+
+  if (pstring != NULL) {
+    if (pledge(pstring, NULL) == -1)
+      goto err;
+  } else if (ppath != NULL) {
+    fp = fopen(ppath, "r");
+    if (fp != NULL) {
+      while ((read = getline(&s, &len, fp)) != -1 ) {
+        if (s[strlen(s)-1] == '\n')
+          s[strlen(s)-1] = '\0';
+        if (pledge(s, NULL) == -1)
+  	  goto err;
+      }
+      fclose(fp);
+    } else {
+      LOG(ERROR) << "fopen() failed, errno: " << errno;
+      return false;
+    }
+  }
+  return true;
+err:
+  LOG(ERROR) << "pledge() failed, errno: " << errno;
+  return false;
+}
+
+bool SandboxLinux::SetUnveil(const std::string process_type, sandbox::mojom::Sandbox sandbox_type) {
+  FILE *fp;
+  char *s = NULL, *cp = NULL, *home = NULL, **ap, *tokens[MAXTOKENS];
+  char path[PATH_MAX];
+  const char *ufile;
+  size_t len = 0, lineno = 0;
+
+  if (process_type.empty()) {
+    ufile = _UNVEIL_MAIN;
+  } else if (process_type == switches::kRendererProcess) {
+    ufile = _UNVEIL_RENDERER;
+  } else if (process_type == switches::kGpuProcess) {
+    ufile = _UNVEIL_GPU;
+  } else if (process_type == switches::kPpapiPluginProcess) {
+    ufile = _UNVEIL_PLUGIN;
+  } else if (process_type == switches::kUtilityProcess) {
+    if (sandbox_type == sandbox::mojom::Sandbox::kNetwork) {
+      ufile = _UNVEIL_UTILITY_NETWORK;
+    } else if (sandbox_type == sandbox::mojom::Sandbox::kAudio) {
+      ufile = _UNVEIL_UTILITY_AUDIO;
+    } else if (sandbox_type == sandbox::mojom::Sandbox::kVideoCapture) {
+      ufile = _UNVEIL_UTILITY_VIDEO;
+    } else {
+      ufile = _UNVEIL_UTILITY;
+    }
+  }
+
+  fp = fopen(ufile, "r");
+  if (fp != NULL) {
+    while (!feof(fp)) {
+      if ((s = fparseln(fp, &len, &lineno, NULL,
+          FPARSELN_UNESCCOMM | FPARSELN_UNESCCONT)) == NULL) {
+        if (ferror(fp)) {
+          LOG(ERROR) << "ferror(), errno: " << errno;
+	  _exit(1);
+	} else {
+          continue;
+	}
+      }
+      cp = s;
+      cp += strspn(cp, " \t\n"); /* eat whitespace */
+      if (cp[0] == '\0')
+        continue;
+
+      for (ap = tokens; ap < &tokens[MAXTOKENS - 1] &&
+          (*ap = strsep(&cp, " \t")) != NULL;) {
+        if (**ap != '\0')
+          ap++;
+      }
+      *ap = NULL;
+
+      if (tokens[1] == NULL) {
+        LOG(ERROR) << ufile << ": line " << lineno << ": must supply value to " << s;
+        _exit(1);
+      }
+
+      if (tokens[0][0] == '~') {
+        if ((home = getenv("HOME")) == NULL || *home == '\0') {
+          LOG(ERROR) << "failed to get home";
+	  _exit(1);
+	}
+        memmove(tokens[0], tokens[0] + 1, strlen(tokens[0]));
+        strncpy(path, home, sizeof(path) - 1);
+        path[sizeof(path) - 1] = '\0';
+        strncat(path, tokens[0], sizeof(path) - 1 - strlen(path));
+      } else {
+        strncpy(path, tokens[0], sizeof(path) - 1);
+        path[sizeof(path) - 1] = '\0';
+      }
+
+      if (unveil(path, tokens[1]) == -1) {
+        LOG(ERROR) << "failed unveiling " << path << " with permissions " << tokens[1];
+        _exit(1);
+      } else {
+        VLOG(1) << "unveiling " << path << " with permissions " << tokens[1];
+      }
+    }
+    fclose(fp);
+  } else {
+        LOG(ERROR) << "failed to open " << ufile << " errno: " << errno;
+        _exit(1);
+  }
+
+  unveil_initialized_ = true;
+
+  return true;
+}
+
+bool SandboxLinux::unveil_initialized() const {
+  return unveil_initialized_;
+}
+
+bool SandboxLinux::InitializeSandbox(sandbox::mojom::Sandbox sandbox_type,
+                                     SandboxLinux::PreSandboxHook hook,
+                                     const Options& options) {
+  DCHECK(!initialize_sandbox_ran_);
+  initialize_sandbox_ran_ = true;
+
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  const std::string process_type =
+      command_line->GetSwitchValueASCII(switches::kProcessType);
+
+  if (command_line->HasSwitch(switches::kNoSandbox))
+    return true;
+
+  VLOG(1) << "SandboxLinux::InitializeSandbox: process_type="
+      << process_type << " sandbox_type=" << GetSandboxTypeInEnglish(sandbox_type);
+
+  // Only one thread is running, pre-initialize if not already done.
+  if (!pre_initialized_)
+    PreinitializeSandbox(sandbox_type);
+
+  // Attempt to limit the future size of the address space of the process.
+  int error = 0;
+  const bool limited_as = LimitAddressSpace(&error);
+  if (error) {
+    // Restore errno. Internally to |LimitAddressSpace|, the errno due to
+    // setrlimit may be lost.
+    errno = error;
+    PCHECK(limited_as);
+  }
+
+  if (process_type.empty()) {
+    // XXX use a file for listing pledges of the main process for now
+    // XXX not having the file is not a fatal error
+    SetPledge(NULL, "/etc/chromium/pledge.main");
+  } else if (process_type == switches::kRendererProcess) {
+    // prot_exec needed by v8
+    // flock needed by sqlite3 locking
+    SetPledge("stdio rpath flock prot_exec recvfd sendfd ps", NULL);
+  } else if (process_type == switches::kGpuProcess) {
+    SetPledge("stdio rpath cpath wpath getpw drm prot_exec recvfd sendfd tmppath", NULL);
+  } else if (process_type == switches::kPpapiPluginProcess) {
+    // prot_exec needed by v8
+    SetPledge("stdio rpath prot_exec recvfd sendfd", NULL);
+  } else if (process_type == switches::kUtilityProcess) {
+    if (sandbox_type == sandbox::mojom::Sandbox::kAudio)
+      SetPledge(NULL, "/etc/chromium/pledge.utility_audio");
+    else if (sandbox_type == sandbox::mojom::Sandbox::kNetwork)
+      SetPledge(NULL, "/etc/chromium/pledge.utility_network");
+    else if (sandbox_type == sandbox::mojom::Sandbox::kVideoCapture)
+      SetPledge(NULL, "/etc/chromium/pledge.utility_video");
+    else
+      SetPledge("stdio rpath cpath wpath fattr flock sendfd recvfd prot_exec", NULL);
+  } else {
+    LOG(ERROR) << "non-pledge()'d process: " << process_type;
+    return false;
+  }
+
+  return true;
+}
+
+bool SandboxLinux::LimitAddressSpace(int* error) {
+#if !defined(ADDRESS_SANITIZER) && !defined(MEMORY_SANITIZER) && \
+    !defined(THREAD_SANITIZER) && !defined(LEAK_SANITIZER)
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  if (SandboxTypeFromCommandLine(*command_line) == sandbox::mojom::Sandbox::kNoSandbox) {
+    return false;
+  }
+
+  // Unfortunately, it does not appear possible to set RLIMIT_AS such that it
+  // will both (a) be high enough to support V8's and WebAssembly's address
+  // space requirements while also (b) being low enough to mitigate exploits
+  // using integer overflows that require large allocations, heap spray, or
+  // other memory-hungry attack modes.
+
+  *error = sandbox::ResourceLimits::Lower(
+      RLIMIT_DATA, static_cast<rlim_t>(sandbox::kDataSizeLimit));
+
+  // Cache the resource limit before turning on the sandbox.
+  base::SysInfo::AmountOfVirtualMemory();
+  base::SysInfo::MaxSharedMemorySize();
+
+  return *error == 0;
+#else
+  base::SysInfo::AmountOfVirtualMemory();
+  return false;
+#endif  // !defined(ADDRESS_SANITIZER) && !defined(MEMORY_SANITIZER) &&
+        // !defined(THREAD_SANITIZER) && !defined(LEAK_SANITIZER)
+}
+
+// static
+std::string SandboxLinux::GetSandboxTypeInEnglish(sandbox::mojom::Sandbox sandbox_type) {
+  switch (sandbox_type) {
+    case sandbox::mojom::Sandbox::kNoSandbox:
+      return "Unsandboxed";
+    case sandbox::mojom::Sandbox::kRenderer:
+      return "Renderer";
+    case sandbox::mojom::Sandbox::kUtility:
+      return "Utility";
+    case sandbox::mojom::Sandbox::kGpu:
+      return "GPU";
+    case sandbox::mojom::Sandbox::kPpapi:
+      return "PPAPI";
+    case sandbox::mojom::Sandbox::kNetwork:
+      return "Network";
+    case sandbox::mojom::Sandbox::kCdm:
+      return "CDM";
+    case sandbox::mojom::Sandbox::kPrintCompositor:
+      return "Print Compositor";
+    case sandbox::mojom::Sandbox::kAudio:
+      return "Audio";
+    case sandbox::mojom::Sandbox::kSpeechRecognition:
+      return "Speech Recognition";
+    case sandbox::mojom::Sandbox::kService:
+      return "Service";
+    case sandbox::mojom::Sandbox::kVideoCapture:
+      return "Video Capture";
+    default:
+      return "Unknown";
+  }
+}
+
+}  // namespace policy
+}  // namespace sandbox
