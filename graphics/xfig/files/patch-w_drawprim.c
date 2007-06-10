--- w_drawprim.c.orig	Sun Jan 14 16:51:46 2007
+++ w_drawprim.c
@@ -512,7 +512,7 @@
     gccache[ERASE] = makegc(ERASE, x_fg_color.pixel, x_bg_color.pixel);
     gccache[INV_PAINT] = makegc(INV_PAINT, x_fg_color.pixel, x_bg_color.pixel);
     /* parse any grid color spec */
-fprintf(stderr,"color = '%s'\n",appres.grid_color);
+if (appres.DEBUG) fprintf(stderr,"color = '%s'\n",appres.grid_color);
     XParseColor(tool_d, tool_cm, appres.grid_color, &tmp_color);
     if (XAllocColor(tool_d, tool_cm, &tmp_color)==0) {
 	fprintf(stderr,"Can't allocate color for grid \n");
