--- w_export.c.orig	Tue Jul 26 09:40:01 2005
+++ w_export.c
@@ -1115,7 +1115,7 @@
 	sprintf(buf, "%.1f", appres.magnification);
 	/* we want to track typing here to update figure size label */
 	mag_spinner = MakeFloatSpinnerEntry(export_panel, &export_mag_text, "magnification",
-			(Widget) NULL, mag_lab, update_mag, buf, 0.0, 10000.0, 1.0, 45);
+			(Widget) NULL, mag_lab, (XtCallbackProc)update_mag, buf, 0.0, 10000.0, 1.0, 45);
 	FirstArg(XtNfromVert, lang_panel);
 	NextArg(XtNtop, XtChainTop);
 	NextArg(XtNbottom, XtChainTop);
