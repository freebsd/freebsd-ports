--- libical/src/libicalvcal/vobject.c	Mon Jan  1 16:37:08 2001
+++ libical/src/libicalvcal/vobject.c.new	Mon Jun  3 02:49:58 2002
@@ -42,7 +42,7 @@
  * vobject, and convert a vobject into its textual representation.
  */
 
-#ifndef	 MWERKS
+#if !defined(MWERKS) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
