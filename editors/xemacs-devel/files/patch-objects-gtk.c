Index: src/objects-gtk.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/objects-gtk.c,v
retrieving revision 1.16
retrieving revision 1.17
diff -u -r1.16 -r1.17
--- src/objects-gtk.c	2005/01/28 02:58:51	1.16
+++ src/objects-gtk.c	2005/12/24 17:33:34	1.17
@@ -485,8 +485,7 @@
 /* X Specific stuff */
 #include <X11/Xatom.h>
 
-/* Unbounded, for sufficiently small values of infinity... */
-#define MAX_FONT_COUNT 5000
+#define MAX_FONT_COUNT INT_MAX
 
 #ifdef MULE
 /* find a font spec that matches font spec FONT and also matches
@@ -536,9 +535,6 @@
   return result;
 }
 #endif /* MULE */
-
-/* Unbounded, for sufficiently small values of infinity... */
-#define MAX_FONT_COUNT 5000
 
 static int
 valid_font_name_p (Display *dpy, char *name)
