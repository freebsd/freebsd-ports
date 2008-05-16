$FreeBSD$

--- ../../j2se/src/solaris/classes/sun/awt/X11/XToolkit.java.orig	2008-05-15 21:06:11.000000000 +0200
+++ ../../j2se/src/solaris/classes/sun/awt/X11/XToolkit.java	2008-05-15 21:07:17.000000000 +0200
@@ -858,7 +858,7 @@
 
     public boolean isTraySupported() {
         int wm = XWM.getWMID();
-        if (wm == XWM.METACITY_WM || wm == XWM.KDE2_WM)
+        if (wm == XWM.METACITY_WM || wm == XWM.KDE2_WM || wm == XWM.ENLIGHTEN_WM)
         {
             return true;
         }
