--- w_cmdpanel.c.orig	Thu Dec 19 18:51:19 2002
+++ w_cmdpanel.c	Wed Aug 31 09:49:42 2005
@@ -37,7 +37,6 @@
 #include "w_icons.h"
 #include "w_indpanel.h"
 #include "w_layers.h"
-#include "w_menuentry.h"
 #include "w_msgpanel.h"
 #include "w_mousefun.h"
 #include "w_print.h"
@@ -46,6 +45,9 @@
 #include "w_setup.h"
 #include "w_style.h"
 #include "w_zoom.h"
+#ifndef XAW3D
+#include "w_menuentry.h"
+#endif
 #ifdef I18N
 #include "d_text.h"
 #endif  /* I18N */
@@ -59,6 +61,15 @@
 Widget	global_popup = 0;
 Widget	global_panel;
 
+#define menu_item_bitmap_width 9
+#define menu_item_bitmap_height 8
+static unsigned char menu_item_bitmap_bits[] = {
+   0x00, 0x01, 0x80, 0x01, 0xc0, 0x00, 0x60, 0x00,
+   0x31, 0x00, 0x1b, 0x00, 0x0e, 0x00, 0x04, 0x00
+};
+
+static Pixmap menu_item_bitmap = None;
+
 /* Widgets holding the ascii values for the string-based settings */
 
 Widget	bal_delay;
@@ -90,6 +101,13 @@
 static int	off_paste_x,off_paste_y;
 static int	orig_paste_x,orig_paste_y;
 
+#ifdef XAW3D
+extern update_indpanel();
+extern update_modepanel();
+extern update_layerpanel();
+extern update_mousepanel();
+extern update_rulerpanel();
+#else
 /* popup message over command button when mouse enters it */
 static void     cmd_balloon_trigger();
 static void     cmd_unballoon();
@@ -97,6 +115,7 @@
 /* popup message over filename window when mouse enters it */
 static void     filename_balloon_trigger();
 static void     filename_unballoon();
+#endif
 
 String  global_translations =
         "<Message>WM_PROTOCOLS: DismissGlobal()\n";
@@ -143,29 +162,28 @@
 	{NULL, 0, NULL},
     };
 
-#define PAGE_BRD_MSG	"page borders   (Meta-B)"
+#define PAGE_BRD_MSG	"page borders    (Meta-B)"
 #define DPTH_MGR_MSG	"depth manager"
-#define INFO_BAL_MSG	"info balloons  (Meta-Y)"
-#define LINE_LEN_MSG	"line lengths   (Meta-L)"
-#define VRTX_NUM_MSG	"vertex numbers         "
+#define INFO_BAL_MSG	"info balloons   (Meta-Y)"
+#define LINE_LEN_MSG	"line lengths    (Meta-L)"
+#define VRTX_NUM_MSG	"vertex numbers"
 
 menu_def view_menu_items[] = {
-	{"Manage Styles...      (Ctrl-Y)",  7, popup_manage_style_panel},
-	{"Redraw                (Ctrl-L)",  0, redisplay_canvas},
-	{"Portrait/Landscape    (Meta-C)",  3, change_orient},
-	{"Zoom In               (Shift-Z)", 5, inc_zoom},
-	{"Zoom Out              (z)",	    5, dec_zoom},
-	{"Zoom to Fit canvas    (Ctrl-Z)",  8, fit_zoom},
-	{"Unzoom",			    0, unzoom},
-	{"Pan to origin",		    0, pan_origin},
-	{"-",				    0, NULL},	/* make a dividing line */
+	{"Manage Styles...     (Ctrl-Y)",  7, popup_manage_style_panel},
+	{"Redraw               (Ctrl-L)",  0, redisplay_canvas},
+	{"Portrait/Landscape   (Meta-C)",  3, change_orient},
+	{"Zoom In              (Shift-Z)", 5, inc_zoom},
+	{"Zoom Out             (z)",	   5, dec_zoom},
+	{"Zoom to Fit canvas   (Ctrl-Z)",  8, fit_zoom},
+	{"Unzoom",			   0, unzoom},
+	{"Pan to origin",		   0, pan_origin},
+	{"-",				   0, NULL},	/* make a dividing line */
 	/* the following menu labels will be refreshed in refresh_view_menu() */
-	/* 2 must be added to the underline value because of the "* " preceding the text */
-	{PAGE_BRD_MSG,			    12, toggle_show_borders},
-	{DPTH_MGR_MSG,			     7, toggle_show_depths},
-	{INFO_BAL_MSG,			     8, toggle_show_balloons},
-	{LINE_LEN_MSG,			    12, toggle_show_lengths},
-	{VRTX_NUM_MSG,			     7, toggle_show_vertexnums},
+	{PAGE_BRD_MSG,			  10, toggle_show_borders},
+	{DPTH_MGR_MSG,			   5, toggle_show_depths},
+	{INFO_BAL_MSG,			   6, toggle_show_balloons},
+	{LINE_LEN_MSG,			   5, toggle_show_lengths},
+	{VRTX_NUM_MSG,			   5, toggle_show_vertexnums},
 	{NULL, 0, NULL},
     };
 
@@ -241,11 +259,13 @@
     NextArg(XtNborderWidth, INTERNAL_BW);
     name_panel = XtCreateManagedWidget("file_name", labelWidgetClass, tool,
 				      Args, ArgCount);
+#ifndef XAW3D
     /* popup balloon when mouse passes over filename */
     XtAddEventHandler(name_panel, EnterWindowMask, False,
 		      filename_balloon_trigger, (XtPointer) name_panel);
     XtAddEventHandler(name_panel, LeaveWindowMask, False,
 		      filename_unballoon, (XtPointer) name_panel);
+#endif
     /* add actions to position the menus if the user uses an accelerator */
     XtAppAddActions(tool_app, menu_actions, XtNumber(menu_actions));
     refresh_view_menu();
@@ -276,12 +296,14 @@
 
 	/* now the menu itself */
 	menu->menuwidget = create_menu_item(menu);
-	
+
+#ifndef XAW3D
 	/* popup when mouse passes over button */
 	XtAddEventHandler(menu->widget, EnterWindowMask, False,
 			  cmd_balloon_trigger, (XtPointer) menu);
 	XtAddEventHandler(menu->widget, LeaveWindowMask, False,
 			  cmd_unballoon, (XtPointer) menu);
+#endif
 
 	return menu->widget;
 }
@@ -304,7 +326,11 @@
 	    sprintf(id, "%1d", j + 1);
 	    FirstArg(XtNvertSpace, 10);
 	    NextArg(XtNunderline, 0); /* underline # digit */
+#ifndef XAW3D
 	    entry = XtCreateWidget(id, figSmeBSBObjectClass, menu, Args, ArgCount);
+#else
+	    entry = XtCreateWidget(id, smeBSBObjectClass, menu, Args, ArgCount);
+#endif
 	    XtAddCallback(entry, XtNcallback, load_recent_file, (XtPointer) my_strdup(id));
 	    if (j < max_recent_files)
 		XtManageChild(entry);
@@ -354,8 +380,13 @@
 		/* normal menu entry */
 		FirstArg(XtNvertSpace, 10);
 		NextArg(XtNunderline, menup->menu[i].u_line); /* any underline */
+#ifndef XAW3D
 		entry = XtCreateManagedWidget(menup->menu[i].name, figSmeBSBObjectClass, 
 					menu, Args, ArgCount);
+#else
+		entry = XtCreateManagedWidget(menup->menu[i].name, smeBSBObjectClass, 
+					menu, Args, ArgCount);
+#endif
 		XtAddCallback(entry, XtNcallback, menup->menu[i].func, 
 					(XtPointer) menup->widget);
 	    }
@@ -381,6 +412,7 @@
     }
 }
 
+#ifndef XAW3D
 /* come here when the mouse passes over a button in the command panel */
 
 static	Widget cmd_balloon_popup = (Widget) 0;
@@ -466,6 +498,7 @@
 	cmd_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 static void
 enter_cmd_but(widget, closure, event, continue_to_dispatch)
@@ -1229,7 +1262,7 @@
 	strcpy(cur_pdfviewer, panel_get_value(pdfview));
 
 	XtPopdown(global_popup);
-
+	
 	refresh_view_menu();
 }
 
@@ -1242,6 +1275,7 @@
 	global_popup = (Widget) 0;
 }
 
+#ifndef XAW3D
 /* come here when the mouse passes over the filename window */
 
 static	Widget filename_balloon_popup = (Widget) 0;
@@ -1313,6 +1347,7 @@
 	filename_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 /*
  * Update the current filename in the name_panel widget, and the xfig icon.
@@ -1459,6 +1494,7 @@
      Boolean state;
 {
     Widget menu, w;
+    Pixmap bitmap;
     char name[60];
     DeclareStaticArgs(10);
 
@@ -1471,25 +1507,36 @@
 	if (w == NULL) {
 	    fprintf(stderr, "xfig: can't find \"viewmenu%s\"\n", name);
 	} else {
-	    if (state)
-		sprintf(name, "Don't show %s", label);
-	    else
-		sprintf(name, "Show %s", label);
-	    if (state)
-		sprintf(name, "* Show %s", label);
-	    else
-		sprintf(name, "  Show %s", label);
+	    sprintf(name, "Show %s", label);
 	    FirstArg(XtNlabel, name);
+	    if (state) {
+		if (menu_item_bitmap == None)
+		    menu_item_bitmap = XCreateBitmapFromData(XtDisplay(menu),
+				RootWindowOfScreen(XtScreen(menu)),
+				(char *)menu_item_bitmap_bits,
+				menu_item_bitmap_width,
+				menu_item_bitmap_height);
+		bitmap = menu_item_bitmap;
+	    } else
+		bitmap = None;
+	    NextArg(XtNleftBitmap, bitmap);
+	    NextArg(XtNleftMargin, menu_item_bitmap_width + 4);
 	    SetValues(w);
 	}
     }
 }
 
-/* update the menu entries with or without an asterisk */
+/* update the menu entries with or without a checkmark,
+	and set or clear all Tip widgets */
 
 void
 refresh_view_menu()
 {
+#ifdef XAW3D
+    int i;
+    register main_menu_info *menu;
+#endif
+
     /* turn off Compose key LED */
     setCompLED(0);
 
@@ -1498,4 +1545,25 @@
     refresh_view_menu_item(INFO_BAL_MSG, appres.showballoons);
     refresh_view_menu_item(LINE_LEN_MSG, appres.showlengths);
     refresh_view_menu_item(VRTX_NUM_MSG, appres.shownums);
+
+#ifdef XAW3D
+    if (appres.showballoons) {
+	XawTipEnable(name_panel, "Current filename");
+	for (i = 0; i < NUM_CMD_MENUS; ++i) {
+	    menu = &main_menus[i];
+	    XawTipEnable(menu->widget, menu->hint);
+	}
+    } else {
+	XawTipDisable(name_panel);
+	for (i = 0; i < NUM_CMD_MENUS; ++i) {
+	    menu = &main_menus[i];
+	    XawTipDisable(menu->widget);
+	}
+    }
+    update_indpanel(cur_indmask);
+    update_modepanel();
+    update_layerpanel();
+    update_mousepanel();
+    update_rulerpanel();
+#endif
 }
