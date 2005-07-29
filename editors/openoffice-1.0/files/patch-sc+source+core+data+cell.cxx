--- sc/source/core/data/cell.cxx.orig	Sun Jul 21 00:39:25 2002
+++ sc/source/core/data/cell.cxx	Sun Jul 21 00:39:26 2002
@@ -75,7 +75,7 @@
 #include <mac_end.h>
 #endif
 
-#ifdef SOLARIS
+#if defined (SOLARIS) || defined (FREEBSD)
 #include <ieeefp.h>
 #elif ( defined ( LINUX ) && ( GLIBC < 2 ) )
 #include <i386/ieeefp.h>
