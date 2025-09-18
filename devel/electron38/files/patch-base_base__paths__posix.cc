--- base/base_paths_posix.cc.orig	2025-03-24 20:50:14 UTC
+++ base/base_paths_posix.cc
@@ -15,6 +15,7 @@
 #include <ostream>
 #include <string>
 
+#include "base/command_line.h"
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/files/file_util.h"
@@ -26,9 +27,13 @@
 #include "base/process/process_metrics.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_BSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#if BUILDFLAG(IS_OPENBSD)
+#include <kvm.h>
+#define MAXTOKENS 2
+#endif
 #elif BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_AIX)
 #include <stdlib.h>
 #endif
@@ -47,8 +52,7 @@ bool PathProviderPosix(int key, FilePath* result) {
       *result = bin_dir;
       return true;
 #elif BUILDFLAG(IS_FREEBSD)
-      int name[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
-      std::optional<std::string> bin_dir = StringSysctl(name, std::size(name));
+      std::optional<std::string> bin_dir = StringSysctl({ CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 });
       if (!bin_dir.has_value() || bin_dir.value().length() <= 1) {
         NOTREACHED() << "Unable to resolve path.";
       }
@@ -62,14 +66,65 @@ bool PathProviderPosix(int key, FilePath* result) {
       *result = FilePath(bin_dir);
       return true;
 #elif BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_AIX)
-      // There is currently no way to get the executable path on OpenBSD
-      char* cpath;
-      if ((cpath = getenv("CHROME_EXE_PATH")) != NULL) {
-        *result = FilePath(cpath);
-      } else {
-        *result = FilePath("/usr/local/chrome/chrome");
+      char *cpath;
+#if !BUILDFLAG(IS_AIX)
+      struct kinfo_file *files;
+      kvm_t *kd = NULL;
+      char errbuf[_POSIX2_LINE_MAX];
+      static char retval[PATH_MAX];
+      int cnt;
+      struct stat sb;
+      pid_t cpid = getpid();
+      bool ret = false;
+
+      const base::CommandLine* command_line =
+          base::CommandLine::ForCurrentProcess();
+
+      VLOG(1) << "PathProviderPosix argv: " << command_line->argv()[0];
+
+      if (realpath(command_line->argv()[0].c_str(), retval) == NULL)
+        goto out;
+
+      if (stat(command_line->argv()[0].c_str(), &sb) < 0)
+        goto out;
+
+      if (!command_line->HasSwitch("no-sandbox")) {
+        ret = true;
+        *result = FilePath(retval);
+        VLOG(1) << "PathProviderPosix (sandbox) result: " << retval;
+        goto out;
       }
-      return true;
+
+      if ((kd = kvm_openfiles(NULL, NULL, NULL, (int)KVM_NO_FILES, errbuf)) == NULL)
+        goto out;
+
+      if ((files = kvm_getfiles(kd, KERN_FILE_BYPID, cpid,
+                                sizeof(struct kinfo_file), &cnt)) == NULL)
+        goto out;
+
+      for (int i = 0; i < cnt; i++) {
+        if (files[i].fd_fd == KERN_FILE_TEXT &&
+            files[i].va_fsid == static_cast<uint32_t>(sb.st_dev) &&
+            files[i].va_fileid == sb.st_ino) {
+          ret = true;
+          *result = FilePath(retval);
+          VLOG(1) << "PathProviderPosix result: " << retval;
+        }
+      }
+out:
+      if (kd)
+        kvm_close(kd);
+      if (!ret) {
+#endif
+        if ((cpath = getenv("CHROME_EXE_PATH")) != NULL)
+          *result = FilePath(cpath);
+        else
+          *result = FilePath("/usr/local/chrome/chrome");
+        return true;
+#if !BUILDFLAG(IS_AIX)
+      }
+      return ret;
+#endif
 #endif
     }
     case DIR_SRC_TEST_DATA_ROOT: {
