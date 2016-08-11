--- simgear/misc/strutils.cxx.orig	2016-05-20 10:23:23.498474613 +0000
+++ simgear/misc/strutils.cxx	2016-05-20 10:27:20.805099873 +0000
@@ -615,7 +615,7 @@
   retcode = strerror_s(buf, sizeof(buf), errnum);
 #elif defined(_GNU_SOURCE)
   return std::string(strerror_r(errnum, buf, sizeof(buf)));
-#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC)
+#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC) || defined(__FreeBSD__)
   int retcode;
   // POSIX.1-2001 and POSIX.1-2008
   retcode = strerror_r(errnum, buf, sizeof(buf));
