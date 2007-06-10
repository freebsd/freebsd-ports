--- w_indpanel.c.orig	Thu Apr  6 12:45:36 2006
+++ w_indpanel.c
@@ -56,7 +56,7 @@
 void	show_depth(ind_sw_info *sw), show_zoom(ind_sw_info *sw);
 void	show_fillstyle(ind_sw_info *sw);
 void	fontpane_popup(int *psfont_adr, int *latexfont_adr, int *psflag_adr, void (*showfont_fn) (/* ??? */), Widget show_widget);
-void	make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap **images, char **texts, Widget parent, XtCallbackProc callback);
+void	make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap *images, char **texts, Widget parent, XtCallbackProc callback);
 void	tog_selective_update(long unsigned int mask);
 unsigned long cur_indmask;	/* mask showing which indicator buttons are mapped */
 void	inc_zoom(ind_sw_info *sw), dec_zoom(ind_sw_info *sw), fit_zoom(ind_sw_info *sw);
@@ -581,7 +581,7 @@
     set_upd = XtCreateManagedWidget("set_upd", commandWidgetClass,
 			upd_ctrl_btns, Args, ArgCount);
     XtAddEventHandler(set_upd, ButtonReleaseMask, False,
-			set_all_update, (XtPointer) 0);
+			(XtEventHandler)set_all_update, (XtPointer) 0);
 
     strcpy(upd_set_sw_info.line1,"Sets all update flags");
     upd_set_sw_info.line2[0] = '\0';
@@ -596,7 +596,7 @@
     clr_upd = XtCreateManagedWidget("clr_upd", commandWidgetClass,
 			upd_ctrl_btns, Args, ArgCount);
     XtAddEventHandler(clr_upd, ButtonReleaseMask, False,
-			clr_all_update, (XtPointer) 0);
+			(XtEventHandler)clr_all_update, (XtPointer) 0);
 
     strcpy(upd_clr_sw_info.line1,"Clears all update flags");
     upd_clr_sw_info.line2[0] = '\0';
@@ -611,7 +611,7 @@
     tog_upd = XtCreateManagedWidget("tog_upd", commandWidgetClass,
 			upd_ctrl_btns, Args, ArgCount);
     XtAddEventHandler(tog_upd, ButtonReleaseMask, False,
-			tog_all_update, (XtPointer) 0);
+			(XtEventHandler)tog_all_update, (XtPointer) 0);
 
     strcpy(upd_tog_sw_info.line1,"Toggles all update flags");
     upd_tog_sw_info.line2[0] = '\0';
@@ -2513,7 +2513,7 @@
     /* thickness spinner */
     sprintf(indbuf,"%d",dimline_thick);
     beside = MakeIntSpinnerEntry(lineform, &line_thick_w, "line_thickness", 
-		below, beside, dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 30);
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 30);
 
     below = beside;
 
@@ -2567,7 +2567,7 @@
     /* thickness spinner */
     sprintf(indbuf,"%d",dimline_boxthick);
     beside = MakeIntSpinnerEntry(boxform, &box_thick_w, "box_line_thickness", 
-		below, beside, dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 30);
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 30);
 
     below = beside;
 
@@ -2649,7 +2649,7 @@
     /* length spinner */
     sprintf(indbuf,"%.1f",dimline_arrowlength);
     beside = MakeFloatSpinnerEntry(arrowform, &arrow_length_w, "arrow_length", 
-		below, beside, dimline_panel_preview, indbuf, 0.1, 200.0, 1.0, 50);
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 0.1, 200.0, 1.0, 50);
 
     below = beside;
 
@@ -2663,7 +2663,7 @@
     /* width spinner */
     sprintf(indbuf,"%.1f",dimline_arrowwidth);
     beside = MakeFloatSpinnerEntry(arrowform, &arrow_width_w, "arrow_width", 
-		below, beside, dimline_panel_preview, indbuf, 0.1, 200.0, 1.0, 50);
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 0.1, 200.0, 1.0, 50);
 
     /****************************/
     /* now frame for Ticks info */
@@ -2688,7 +2688,7 @@
     /* "Ticks" checkbutton */
     below = CreateCheckbutton("Show ticks", "ticks", tickform, below, (Widget) NULL,
 				MANAGE, LARGE_CHK, &dimline_ticks,
-				dimline_panel_preview, (Widget) NULL);
+				(XtCallbackProc)dimline_panel_preview, (Widget *) NULL);
 
     /* Tick Thickness label */
     FirstArg(XtNlabel, "Thickness");
@@ -2700,7 +2700,7 @@
     /* thickness spinner */
     sprintf(indbuf,"%d",dimline_tickthick);
     (void) MakeIntSpinnerEntry(tickform, &tick_thick_w, "tick_line_thickness", 
-		below, beside, dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 28);
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 0, MAX_LINE_WIDTH, 1, 28);
 
     /***************************/
     /* now frame for Text info */
@@ -2737,7 +2737,7 @@
 			psfont_menu_bitmaps[dimline_font + 1] :
 			latexfont_menu_bitmaps[dimline_font]);
     font_button = XtCreateManagedWidget("font", commandWidgetClass, textform, Args, ArgCount);
-    XtAddCallback(font_button, XtNcallback, dimline_font_popup, (XtPointer) NULL);
+    XtAddCallback(font_button, XtNcallback, (XtCallbackProc)dimline_font_popup, (XtPointer) NULL);
 
     below = font_button;
 
@@ -2752,7 +2752,7 @@
     /* size spinner */
     sprintf(indbuf,"%d",dimline_fontsize);
     beside = MakeIntSpinnerEntry(textform, &font_size_w, "font_size", 
-		below, beside, dimline_panel_preview, indbuf, 
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 
 		MIN_FONT_SIZE, MAX_FONT_SIZE, 1, 30);
 
     below = beside;
@@ -2796,7 +2796,7 @@
     /* number of decimal places spinner */
     sprintf(indbuf,"%d",dimline_prec);
     below = MakeIntSpinnerEntry(stringform, &dimline_precw, "precision", 
-		below, beside, dimline_panel_preview, indbuf, 
+		below, beside, (XtCallbackProc)dimline_panel_preview, indbuf, 
 		0, 10, 1, 30);
 
     /* Fixed text checkbutton */
@@ -4776,7 +4776,7 @@
  */
 
 void
-make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap **images, char **texts, Widget parent, XtCallbackProc callback)
+make_pulldown_menu_images(choice_info *entries, Cardinal nent, Pixmap *images, char **texts, Widget parent, XtCallbackProc callback)
 {
     Widget	    pulldown_menu, entry;
     char	    buf[64];
