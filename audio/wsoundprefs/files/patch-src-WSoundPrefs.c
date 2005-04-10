--- src/WSoundPrefs.c.orig	Sat Mar  4 21:46:11 2000
+++ src/WSoundPrefs.c	Sun Apr 10 21:37:11 2005
@@ -378,7 +378,7 @@
 		WMResizeWidget(panel->iconL, 72, 72);
 		WMMoveWidget(panel->iconL, 82, 10);
 		WMSetLabelImagePosition(panel->iconL, WIPImageOnly);
-		WMSetLabelImage(panel->iconL, WMGetApplicationIconImage(scr));
+		WMSetLabelImage(panel->iconL, WMGetApplicationIconPixmap(scr));
 		
 		/* Title */
 		panel->titleL = WMCreateLabel(panel->aboutF);
@@ -407,7 +407,7 @@
 		WMResizeWidget(panel->copyrightL, 448, 20);
 		WMMoveWidget(panel->copyrightL, 8, 178);
 		WMSetLabelTextAlignment(panel->copyrightL, WACenter);
-		font = WMCreateNormalFont(scr, "-*-helvetica-medium-r-normal-*-10-*-*-*-*-*-*-*");
+		font = WMCreateFont(scr, "-*-helvetica-medium-r-normal-*-10-*-*-*-*-*-*-*");
 		if (font)
 			WMSetLabelText(panel->copyrightL, "Copyright \xa9 1999 The Az\xe5rg-r\xfbh");
 		else {
