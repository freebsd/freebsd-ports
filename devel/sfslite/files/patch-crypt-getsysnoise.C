--- crypt/getsysnoise.C.orig	2005-11-01 16:20:36.000000000 +0000
+++ crypt/getsysnoise.C	2007-07-12 22:38:59.000000000 +0000
@@ -27,57 +27,57 @@
 #include <sys/resource.h>
 
 char *const noiseprogs[][5] = {
-  { PATH_PS, "laxwww" },
-  { PATH_PS, "-al" },
-  { PATH_LS, "-nfail", "/tmp/." },
+  { (char *)PATH_PS, (char *)"laxwww" },
+  { (char *)PATH_PS, (char *)"-al" },
+  { (char *)PATH_LS, (char *)"-nfail", (char *)"/tmp/." },
 #ifdef PATH_NETSTAT
-  { PATH_NETSTAT, "-s" },
-  { PATH_NETSTAT, "-an" },
-  { PATH_NETSTAT, "-in" },
+  { (char *)PATH_NETSTAT, (char *)"-s" },
+  { (char *)PATH_NETSTAT, (char *)"-an" },
+  { (char *)PATH_NETSTAT, (char *)"-in" },
 #endif /* PATH_NETSTAT */
 #ifdef PATH_NTPQ
-  { PATH_NTPQ, "-np" },
+  { (char *)PATH_NTPQ, (char *)"-np" },
 #endif /* PATH_NTPQ */
 #ifdef PATH_W
-  { PATH_W },
+  { (char *)PATH_W },
 #endif /* PATH_W */
 #ifdef PATH_NFSSTAT
-  { PATH_NFSSTAT },
+  { (char *)PATH_NFSSTAT },
 #endif /* PATH_NFSSTAT */
 #ifdef PATH_VNSTAT
-  { PATH_VMSTAT },
-  { PATH_VMSTAT, "-i" },
-  { PATH_VMSTAT, "-s" },
+  { (char *)PATH_VMSTAT },
+  { (char *)PATH_VMSTAT, (char *)"-i" },
+  { (char *)PATH_VMSTAT, (char *)"-s" },
 #endif /* PATH_VNSTAT */
 #ifdef PATH_IOSTAT
 #if defined (__linux__) || defined (__osf__)
-  { PATH_IOSTAT },
+  { (char *)PATH_IOSTAT },
 #else /* not linux or osf */
-  { PATH_IOSTAT, "-I" },
+  { (char *)PATH_IOSTAT, (char *)"-I" },
 #endif /* not linux or osf */
 #endif /* PATH_IOSTAT */
 #ifdef PATH_LSOF
-  { PATH_LSOF, "-bwn",
+  { (char *)PATH_LSOF, (char *)"-bwn",
 # ifdef LSOF_DEVCACHE
-    "-Di"
+    (char *)"-Di"
 # endif /* LSOF_DEVCACHE */
   },
 #else /* no lsof */
 # ifdef PATH_FSTAT
-  { PATH_FSTAT },
+  { (char *)PATH_FSTAT },
 # endif /* PATH_FSTAT */
 # ifdef PATH_PSTAT
-  { PATH_PSTAT, "-f" },
+  { (char *)PATH_PSTAT, (char *)"-f" },
 # endif /* PATH_PSTAT */
 #endif /* no lsof */
 #ifdef PATH_PSTAT
-  { PATH_PSTAT, "-t" },
+  { (char *)PATH_PSTAT, (char *)"-t" },
 # if defined (__OpenBSD__) || defined (__NetBSD__) || defined (__FreeBSD__)
-  { PATH_PSTAT, "-v" },
+  { (char *)PATH_PSTAT, (char *)"-v" },
 # endif /* open/net/freebsd */
 #endif /* PATH_PSTAT */
 #ifdef PATH_NFSSTAT
-  { PATH_NFSSTAT },
+  { (char *)PATH_NFSSTAT },
 #endif /* PATH_NFSSTAT */
 #if 0
   { PATH_RUP },
