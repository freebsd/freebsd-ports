--- jdk/src/solaris/classes/sun/awt/X11/XWM.java.orig	2015-02-01 19:16:25.000000000 -0800
+++ jdk/src/solaris/classes/sun/awt/X11/XWM.java	2015-02-01 19:16:51.000000000 -0800
@@ -578,7 +578,7 @@
     }
 
     static boolean isMutter() {
-        return isNetWMName("Mutter");
+        return isNetWMName("Mutter") || isNetWMName("GNOME Shell");
     }
 
     static boolean isNonReparentingWM() {
