--- include/system.h.orig	Sat Aug 30 09:07:23 2003
+++ include/system.h	Tue Sep  2 00:39:39 2003
@@ -79,7 +79,9 @@
 # if !defined(__SC__) && !defined(LINUX)
 E  long NDECL(random);
 # endif
-# if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
+# if defined(__FreeBSD__)
+E void FDECL(srandom, (unsigned long));
+# elif (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 # else
 #  if !defined(bsdi) && !defined(__FreeBSD__)
