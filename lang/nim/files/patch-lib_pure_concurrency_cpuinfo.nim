--- lib/pure/concurrency/cpuinfo.nim.orig	2026-10-18 17:48:12 UTC
+++ lib/pure/concurrency/cpuinfo.nim
@@ -78,15 +78,18 @@ else:
       getSystemInfo(addr si)
       result = int(si.dwNumberOfProcessors)
     elif defined(macosx) or defined(bsd):
-      let dest = addr result
-      var len = sizeof(result).csize_t
+      # hw.ncpu is a C int; reading it into the full-width result would leave
+      # it in the high word on big-endian hosts
+      var ncpu: cint = 0
+      let dest = addr ncpu
+      var len = sizeof(ncpu).csize_t
       when defined(macosx):
         # alias of "hw.activecpu"
         if sysctlbyname("hw.logicalcpu", dest, len, nil, 0) == 0:
-          return
+          return int(ncpu)
       var mib = [CTL_HW, HW_NCPU]
       if sysctl(mib, 2, dest, len, nil, 0) == 0:
-        return
+        return int(ncpu)
     elif defined(hpux):
       result = mpctl(MPC_GETNUMSPUS, nil, nil)
     elif defined(irix):
