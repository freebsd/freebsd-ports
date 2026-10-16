--- /dev/null	2026-10-16 00:00:00 UTC
+++ src/mongo/util/processinfo_freebsd.cpp
@@ -0,0 +1,162 @@
+// Copyright (c) MongoDB, Inc.
+// SPDX-License-Identifier: SSPL-1.0
+
+#include "mongo/bson/bsonobjbuilder.h"
+#include "mongo/logv2/log.h"
+#include "mongo/util/processinfo.h"
+
+#include <cerrno>
+#include <cstring>
+#include <string>
+
+#include <boost/none.hpp>
+#include <boost/optional.hpp>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/user.h>
+#include <unistd.h>
+
+#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kControl
+
+namespace mongo {
+
+namespace {
+
+/**
+ * Get a sysctl value by name, or defaultValue on failure. Returns 0 or an errno value.
+ */
+template <typename T>
+int getSysctlByNameWithDefault(const char* sysctlName, const T& defaultValue, T* result) {
+    T value{};
+    size_t len = sizeof(value);
+    if (sysctlbyname(sysctlName, &value, &len, nullptr, 0) == -1) {
+        *result = defaultValue;
+        return errno;
+    }
+    if (len != sizeof(value)) {
+        *result = defaultValue;
+        return EINVAL;
+    }
+    *result = value;
+    return 0;
+}
+
+template <>
+int getSysctlByNameWithDefault<std::string>(const char* sysctlName,
+                                            const std::string& defaultValue,
+                                            std::string* result) {
+    char value[256] = {0};
+    size_t len = sizeof(value) - 1;
+    if (sysctlbyname(sysctlName, value, &len, nullptr, 0) == -1) {
+        *result = defaultValue;
+        return errno;
+    }
+    *result = value;
+    return 0;
+}
+
+bool getKinfoProc(pid_t pid, struct kinfo_proc* kp) {
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};
+    size_t len = sizeof(*kp);
+    return sysctl(mib, 4, kp, &len, nullptr, 0) == 0 && len == sizeof(*kp);
+}
+
+}  // namespace
+
+ProcessInfo::ProcessInfo(ProcessId pid) : _pid(pid) {}
+
+ProcessInfo::~ProcessInfo() {}
+
+bool ProcessInfo::supported() {
+    return true;
+}
+
+// The number of CPUs in the cpuset of this process.
+boost::optional<uint64_t> ProcessInfo::getNumCoresForProcess() {
+    cpuset_t mask;
+    CPU_ZERO(&mask);
+    if (cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1, sizeof(mask), &mask) == 0) {
+        int count = CPU_COUNT(&mask);
+        if (count > 0)
+            return static_cast<uint64_t>(count);
+    }
+    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
+    if (nprocs > 0)
+        return static_cast<uint64_t>(nprocs);
+    return boost::none;
+}
+
+int ProcessInfo::getVirtualMemorySize() {
+    struct kinfo_proc kp;
+    if (!getKinfoProc(_pid.toNative(), &kp))
+        return -1;
+    return kp.ki_size / 1024 / 1024;  // convert from bytes to MB
+}
+
+int ProcessInfo::getResidentSize() {
+    struct kinfo_proc kp;
+    if (!getKinfoProc(_pid.toNative(), &kp))
+        return -1;
+    return static_cast<long long>(kp.ki_rssize) * sysconf(_SC_PAGESIZE) / 1024 /
+        1024;  // convert from pages to MB
+}
+
+void ProcessInfo::getExtraInfo(BSONObjBuilder& info) {}
+
+void ProcessInfo::SystemInfo::collectSystemInfo() {
+    osType = "BSD";
+    osName = "FreeBSD";
+
+    int status = getSysctlByNameWithDefault("kern.osrelease", std::string("unknown"), &osVersion);
+    if (status != 0)
+        LOGV2(23332,
+              "Unable to collect OS Version.",
+              "errno"_attr = status,
+              "msg"_attr = strerror(status));
+
+    status = getSysctlByNameWithDefault("hw.machine_arch", std::string("unknown"), &cpuArch);
+    if (status != 0)
+        LOGV2(23333,
+              "Unable to collect Machine Architecture.",
+              "errno"_attr = status,
+              "msg"_attr = strerror(status));
+    addrSize = cpuArch.find("64") != std::string::npos ? 64 : 32;
+
+    u_long physmem;
+    status = getSysctlByNameWithDefault("hw.physmem", u_long{0}, &physmem);
+    memSize = physmem;
+    memLimit = memSize;
+    if (status != 0)
+        LOGV2(23334,
+              "Unable to collect Physical Memory.",
+              "errno"_attr = status,
+              "msg"_attr = strerror(status));
+
+    int ncpu;
+    status = getSysctlByNameWithDefault("hw.ncpu", 1, &ncpu);
+    numCores = ncpu;
+    if (status != 0)
+        LOGV2(23335,
+              "Unable to collect Number of CPUs.",
+              "errno"_attr = status,
+              "msg"_attr = strerror(status));
+
+    int cores;
+    if (getSysctlByNameWithDefault("kern.smp.cores", ncpu, &cores) == 0 && cores > 0)
+        numPhysicalCores = cores;
+    else
+        numPhysicalCores = numCores;
+
+    pageSize = static_cast<unsigned long long>(sysconf(_SC_PAGESIZE));
+
+    hasNuma = false;
+
+    // The appropriate system parameter is "kern.ipc.soacceptqueue", but to
+    // simplify testing we hardcode to `SOMAXCONN`.
+    defaultListenBacklog = SOMAXCONN;
+}
+
+}  // namespace mongo
