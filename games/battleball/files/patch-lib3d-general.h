--- lib3d/general.h.orig	Fri Sep  3 04:25:19 1999
+++ lib3d/general.h	Fri Jul 18 17:42:41 2003
@@ -25,9 +25,15 @@
 typedef unsigned int  uint;
 typedef unsigned long ulong;
 
+#ifdef __GNUC__
+#if __GNUC__ < 3
 #define and &&
 #define or  ||
 #define not !
+#endif
+
+// TODO - what about non-GNU C++ compilers?
+#endif
 
 #define forii(limit) for (int i= 0; i <limit; i++)
 #define forij(limit) for (int j= 0; j <limit; j++)
