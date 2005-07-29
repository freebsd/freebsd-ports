--- cppu/inc/uno/lbnames.h.orig	Fri May 31 00:06:58 2002
+++ cppu/inc/uno/lbnames.h	Fri May 31 00:07:22 2002
@@ -94,7 +94,7 @@
 #define	__CPPU_ENV gcc2
 #elif (__GNUC__ == 2)
 #error "Tested gcc 2 versions are 2.91 and 2.95.  Patch uno/lbnames.h to try your gcc 2 version."
-#elif (__GNUC__ == 3 && __GNUC_MINOR__ == 0)
+#elif (__GNUC__ == 3 && (__GNUC_MINOR__ == 0 || __GNUC_MINOR__ == 1 || __GNUC_MINOR__ == 2))
 #define	__CPPU_ENV gcc3
 #elif (__GNUC__ == 3)
 #error "Tested gcc 3 version is 3.0.  Patch uno/lbnames.h to try your gcc 3 version."
