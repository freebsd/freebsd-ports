--- main.c.orig	Sun Jan 14 16:24:26 2007
+++ main.c
@@ -267,9 +267,9 @@
     {"pageborder", "Color",   XtRString, sizeof(char *),
       XtOffset(appresPtr, pageborder), XtRString, (caddr_t) "lightblue"},
     {"browser", "Browser", XtRString, sizeof(char *),
-      XtOffset(appresPtr, browser), XtRString, (caddr_t) "netscape"},
+      XtOffset(appresPtr, browser), XtRString, (caddr_t) "firefox"},
     {"pdfviewer", "Viewer", XtRString, sizeof(char *),
-      XtOffset(appresPtr, pdf_viewer), XtRString, (caddr_t) "acroread"},
+      XtOffset(appresPtr, pdf_viewer), XtRString, (caddr_t) "xpdf"},
     {"spinner_delay", "spinnerDelay",   XtRInt, sizeof(int),
       XtOffset(appresPtr, spinner_delay), XtRImmediate, (caddr_t) 500},
     {"spinner_rate", "spinnerRate",   XtRInt, sizeof(int),
@@ -623,7 +623,7 @@
 int setup_visual (int *argc_p, char **argv, Arg *args);
 void get_pointer_mapping (void);
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     Widget	    children[NCHILDREN];
     XEvent	    event;
@@ -1515,7 +1515,7 @@
 	    if (XK_F1 <= key && key <= XK_F35) {
 	      XtDispatchEvent(&event);
 	    } else {
-	      canvas_selected(canvas_sw, &event, NULL, NULL);
+	      canvas_selected(canvas_sw, (XButtonEvent *)&event, NULL, NULL);
 	    }
 	  } else {
 	    XtDispatchEvent(&event);
