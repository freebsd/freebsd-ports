--- acfax.c.orig	1998-10-06 21:32:35 UTC
+++ acfax.c
@@ -108,7 +108,7 @@ struct prginfo {
   String sizedesc;
 } prg_info;
 
-Display	*dpy;		/* the X-Display to use */
+extern Display	*dpy;		/* the X-Display to use */
 Screen	*scr;		/* screen of the display */
 Pixmap	cpxmap;		/* The "backing store" for the canvas-widget */
 GC	cgc;		/* GC for XPutImage from horimage/verimage to cpxmap */
@@ -739,7 +739,7 @@ void quit_cb(Widget w, XtPointer client_data, XtPointe
     exit(0);
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   int i;
   Pixel respix[20];
@@ -795,7 +795,7 @@ void main(int argc, char **argv)
   mode_notify = op_changed;
   /* that's a hard one, but should set up all things right.... */
   XtVaGetValues(canvas, XtNwidth, &wid, XtNheight, &hei, NULL);
-  setup_fax(120, 288, (FAX_CNOR | FAX_CUNFL | FAX_CROT0 |
+  setup_fax(120, 576, (FAX_CNOR | FAX_CUNFL | FAX_CROT0 |
 	FAX_LEF2RIG | FAX_TOP2BOT | FAX_HOR | FAX_PBLK | FAX_GRAY),
 	toplevel, (unsigned)wid, (unsigned)hei, 500, (MOD_FM | FIL_MIDL));
   aptstart = 300;
