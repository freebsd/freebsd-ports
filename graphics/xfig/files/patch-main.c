--- main.c.orig	2011-06-18 20:50:16.000000000 -0700
+++ main.c	2011-06-18 20:50:52.000000000 -0700
@@ -273,7 +273,7 @@
     {"browser", "Browser", XtRString, sizeof(char *),
       XtOffset(appresPtr, browser), XtRString, (caddr_t) "firefox"},
     {"pdfviewer", "Viewer", XtRString, sizeof(char *),
-      XtOffset(appresPtr, pdf_viewer), XtRString, (caddr_t) "acroread"},
+      XtOffset(appresPtr, pdf_viewer), XtRString, (caddr_t) "xpdf"},
     {"spinner_delay", "spinnerDelay",   XtRInt, sizeof(int),
       XtOffset(appresPtr, spinner_delay), XtRImmediate, (caddr_t) 500},
     {"spinner_rate", "spinnerRate",   XtRInt, sizeof(int),
@@ -629,7 +629,7 @@
 int setup_visual (int *argc_p, char **argv, Arg *args);
 void get_pointer_mapping (void);
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     Widget	    children[NCHILDREN];
     XEvent	    event;
