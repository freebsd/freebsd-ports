Index: lwlib/xlwmenu.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lwlib/xlwmenu.c,v
retrieving revision 1.38
diff -u -r1.38 xlwmenu.c
--- lwlib/xlwmenu.c	2005/11/26 11:45:59	1.38
+++ lwlib/xlwmenu.c	2005/12/20 13:04:56
@@ -2828,8 +2828,9 @@
 	  XColor xcolor;
 	  Visual *visual;
 	  int ignore;
+	  Colormap cmap;
 	  visual_info_from_widget ((Widget) mw, &visual, &ignore);
-	  Colormap cmap = mw->core.colormap;
+	  cmap = mw->core.colormap;
 	  xcolor.pixel = mw->core.background_pixel;
 	  XQueryColor (dpy, cmap, &xcolor);
 	  xcolor.red   = (xcolor.red   * 17) / 20;
