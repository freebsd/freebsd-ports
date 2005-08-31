--- w_library.c.orig	Mon Nov 11 18:58:48 2002
+++ w_library.c	Wed Aug 31 09:49:42 2005
@@ -40,7 +40,9 @@
 #include "w_setup.h"
 #include "w_icons.h"
 #include "w_zoom.h"
+#ifndef XAW3D
 #include "SmeCascade.h"
+#endif
 
 #ifdef HAVE_NO_DIRENT
 #include <sys/dir.h>
@@ -73,7 +75,10 @@
 static Widget	library_popup=0;
 static Widget	put_cur_obj;
 static Widget	library_form, title;
-static Widget	lib_obj_label, library_label, library_menu, library_menu_button;
+static Widget	lib_obj_label, library_label, library_menu_button;
+#ifndef XAW3D
+static Widget	library_menu;
+#endif
 static Widget	sel_view_button;
 static Widget	object_form;
 static Widget	icon_form, icon_viewport, icon_box;
@@ -272,8 +277,10 @@
     Dimension	    lwidth, lheight;
     Dimension	    lawidth, laheight;
 
+#ifndef XAW3D
     /* pop down the menu */
     XtPopdown(library_menu);
+#endif
 
     /* if already in the middle of loading a library, return */
     if (loading_library) {
@@ -629,8 +636,8 @@
 					    menuButtonWidgetClass,
 					    library_form, Args, ArgCount);
     /* make the menu and attach it to the button */
-    (void) make_library_menu(library_menu_button, 
-    					library_rec, num_library_names);
+    (void) make_library_menu(library_menu_button, "menu",
+    			library_rec, num_library_names);
 
     if (!actions_added) {
 	XtAppAddActions(tool_app, library_actions, XtNumber(library_actions));
@@ -1000,20 +1007,27 @@
     XtInstallAccelerators(library_form, cancel);
 }
 
+#ifndef XAW3D
 extern void popdown_subs();
+#endif
 
 static Widget
-make_library_menu(parent, librec, num)
+make_library_menu(parent, name, librec, num)
     Widget	     parent;
+    char	    *name;
     struct lib_rec  *librec[];
     int		     num;
 {
-    Widget	     menu, entry, submenu;
-    char	     name[200];
+    Widget	     menu, entry;
+#ifndef XAW3D
+    Widget	     submenu;
+#endif
+    char	     menu_name[200];
     int		     i;
 
-    menu = XtCreatePopupShell("menu", simpleMenuWidgetClass, 
-				parent, NULL, ZERO);
+    menu = XtCreatePopupShell(name, simpleMenuWidgetClass, 
+			      parent, NULL, ZERO);
+#ifndef XAW3D
     /* if this is the toplevel menu, add a callback to popdown any submenus if
        the user releases the pointer button outside a submenu */
     if (XtIsSubclass(parent, menuButtonWidgetClass)) {
@@ -1021,29 +1035,54 @@
 	library_menu = menu;
 	XtAddCallback(menu, XtNpopdownCallback, popdown_subs, (XtPointer) NULL);
     }
-    
+#endif
+
     for (i = 0; i < num; i++) {
-	/* add one blank in front and after name to allow space for diamond and/or arrow */
-	sprintf(name," %s ",librec[i]->name);
+#ifndef XAW3D
+	sprintf(menu_name, " %s ", librec[i]->name);
+#else
+	sprintf(menu_name, "%sMenu", librec[i]->name);
+#endif
 	if (librec[i]->nsubs) {
-	    submenu = make_library_menu(menu, librec[i]->subdirs, 
-	    					librec[i]->nsubs);
+#ifndef XAW3D
+	    submenu = make_library_menu(menu, menu_name, librec[i]->subdirs,
+					librec[i]->nsubs);
 	    FirstArg(XtNsubMenu, submenu);
-	    NextArg(XtNrightBitmap, menu_cascade_arrow); /* use arrow to indicate cascade */
-	    NextArg(XtNrightMargin, 9);			/* room to the right of the arrow */
+	    NextArg(XtNrightMargin, 9);
+#else
+	    FirstArg(XtNmenuName, XtNewString(menu_name));
+#endif
+	    NextArg(XtNrightBitmap, menu_cascade_arrow);
 	    if (librec[i]->figs_at_top) {
-		NextArg(XtNselectCascade, True);	/* if there are fig files, make the */
-		NextArg(XtNleftBitmap, diamond_pixmap);	/* cascade selectable and add a bitmap */
-	    }						/* in the left bitmap of the BSB */
-	    entry = XtCreateManagedWidget(name, smeCascadeObjectClass, menu, 
-				Args, ArgCount);
-	    /* if there are fig files at this level, make the dir name selectable */
+#ifndef XAW3D
+		NextArg(XtNselectCascade, True);
+#endif
+		NextArg(XtNleftBitmap, diamond_pixmap);
+	    }
+#ifndef XAW3D
+	    entry = XtCreateManagedWidget(menu_name, smeCascadeObjectClass,
+					  menu, Args, ArgCount);
+#else
+	    entry = XtCreateManagedWidget(librec[i]->name, smeBSBObjectClass,
+					  menu, Args, ArgCount);
+#endif
 	    if (librec[i]->figs_at_top)
-		XtAddCallback(entry, XtNcallback, load_library, (XtPointer) librec[i]);
+		XtAddCallback(entry, XtNcallback, load_library,
+			      (XtPointer) librec[i]);
+#ifdef XAW3D
+	    (void) make_library_menu(menu, menu_name, librec[i]->subdirs,
+				     librec[i]->nsubs);
+#endif
 	} else {
-	    entry = XtCreateManagedWidget(name, smeCascadeObjectClass, menu, 
-				NULL, ZERO);
-	    XtAddCallback(entry, XtNcallback, load_library, (XtPointer) librec[i]);
+#ifndef XAW3D
+	    entry = XtCreateManagedWidget(menu_name, smeCascadeObjectClass,
+					  menu, NULL, ZERO);
+#else
+	    entry = XtCreateManagedWidget(librec[i]->name, smeBSBObjectClass,
+					  menu, NULL, ZERO);
+#endif
+	    XtAddCallback(entry, XtNcallback, load_library,
+			  (XtPointer) librec[i]);
 	  }
     }
     return menu;
