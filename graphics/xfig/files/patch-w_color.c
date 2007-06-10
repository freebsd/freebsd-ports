--- w_color.c.orig	Thu Oct 27 10:39:18 2005
+++ w_color.c
@@ -144,13 +144,13 @@
 			mixed_color[color_el+2].rgb/256: user_colors[color_el].rgb/256)
 #define CHANGE_RED(element) \
 		pass_value = 1.0 - (float)(COLOR(element,red)/255.0); \
-		Thumbed(redScroll, S_RED, (XtPointer)(&pass_value))
+		Thumbed(redScroll, (XtPointer)S_RED, (XtPointer)(&pass_value))
 #define CHANGE_GREEN(element) \
 		pass_value = 1.0 - (float)(COLOR(element,green)/255.0); \
-		Thumbed(greenScroll, S_GREEN, (XtPointer)(&pass_value))
+		Thumbed(greenScroll, (XtPointer)S_GREEN, (XtPointer)(&pass_value))
 #define CHANGE_BLUE(element) \
 		pass_value = 1.0 - (float)(COLOR(element,blue)/255.0); \
-		Thumbed(blueScroll, S_BLUE, (XtPointer)(&pass_value))
+		Thumbed(blueScroll, (XtPointer)S_BLUE, (XtPointer)(&pass_value))
 
 static RGB	rgb_values[2];
 static HSV	hsv_values;
@@ -192,8 +192,8 @@
 	{"pick_memory", _pick_memory},
 	{"update_scrl_triple", update_scrl_triple},
 	{"update_from_triple", update_from_triple},
-	{"set_std_color", _set_std_color},
-	{"set_color_ok", set_color_ok},
+	{"set_std_color", (XtActionProc)_set_std_color},
+	{"set_color_ok", (XtActionProc)set_color_ok},
 };
 
 static String set_panel_translations =
@@ -1864,17 +1864,17 @@
 
 	if (buttons_down & S_RED)	{
 		pass_value = 1.0 - (float) red_pos/255;
-		Thumbed(redScroll, S_RED, (XtPointer)(&pass_value));
+		Thumbed(redScroll, (XtPointer)S_RED, (XtPointer)(&pass_value));
 	}
 
 	if (buttons_down & S_GREEN)	{
 		pass_value = 1.0 - (float) green_pos/255;
-		Thumbed(greenScroll, S_GREEN, (XtPointer)(&pass_value));
+		Thumbed(greenScroll, (XtPointer)S_GREEN, (XtPointer)(&pass_value));
 	}
 
 	if (buttons_down & S_BLUE)	{
 		pass_value = 1.0 - (float) blue_pos/255;
-		Thumbed(blueScroll, S_BLUE, (XtPointer)(&pass_value));
+		Thumbed(blueScroll, (XtPointer)S_BLUE, (XtPointer)(&pass_value));
 	}
 
 	do_change = True;
