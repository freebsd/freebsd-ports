$FreeBSD$

--- ../../j2se/src/solaris/native/sun/awt/fontpath.c.orig	Fri Dec  8 11:59:25 2006
+++ ../../j2se/src/solaris/native/sun/awt/fontpath.c	Fri Dec  8 12:00:06 2006
@@ -495,10 +495,10 @@
     char *ptr;
 
 #if defined(__linux__) || defined(_ALLBSD_SOURCE)
-    ptr = "/usr/X11R6/lib/X11/fonts/Type1:"
-          "/usr/X11R6/lib/X11/fonts/TrueType:"
-          "/usr/X11R6/lib/X11/fonts/tt:"
-          "/usr/share/fonts/ja/TrueType";
+    ptr = "%%LOCALBASE%%/lib/X11/fonts/Type1:"
+          "%%LOCALBASE%%/lib/X11/fonts/TrueType:"
+          "%%LOCALBASE%%/lib/X11/fonts/tt:"
+          "%%LOCALBASE%%/fonts/ja/TrueType";
 #elif defined( HEADLESS )
     ptr = getSolarisFontLocations(env, (int) (noType1==JNI_TRUE));
 #elif SCAN_FONT_DIRS
