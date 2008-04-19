$FreeBSD$

--- ../src/solaris/native/sun/awt/font/fontpath.c.orig	Fri Dec  8 10:52:19 2006
+++ ../src/solaris/native/sun/awt/font/fontpath.c	Fri Dec  8 10:54:02 2006
@@ -426,7 +426,7 @@
 JNIEXPORT jstring JNICALL Java_sun_awt_font_NativeFontWrapper_getFontPath(JNIEnv *env, jclass obj, jboolean noType1)
 {
 #ifndef __solaris__
-   char *ptr   = "/usr/X11R6/lib/X11/fonts/Type1:/usr/X11R6/lib/X11/fonts/TrueType:/usr/X11R6/lib/X11/fonts/tt";
+   char *ptr   = "%%LOCALBASE%%/lib/X11/fonts/Type1:%%LOCALBASE%%/lib/X11/fonts/TrueType:%%LOCALBASE%%/lib/X11/fonts/tt";
 #else
     char *ptr   = getSolarisFontLocations((int) (noType1==JNI_TRUE));
 #endif
