--- sr.c.orig	1997-08-04 12:17:37.000000000 +0200
+++ sr.c	2024-10-22 23:55:52.935250000 +0200
@@ -4,11 +4,12 @@
 
 #ifndef lint
 static char *rcsid_sr_c = "$XConsortium: sr.c,v 1.10 88/10/22 10:37:58 jim Exp $";
-#endif	lint
+#endif	/* lint */
 
 /* Slide Rule */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 #include <signal.h>
 #include <X11/Xos.h>
@@ -53,8 +54,8 @@
 extern XFontStruct *kfontinfo;
 Font	scalefont, sscalefont;
 extern Pixmap backgroundPix,regBorder,dimBorder,IconPix;
-Pixmap	slidePix = NULL;
-Pixmap	framePix = NULL;
+Pixmap	slidePix;
+Pixmap	framePix;
 extern Cursor	arrow;
 GC	sgc, cgc;
 int	height,scalelen,width,fheight,foffset;
@@ -63,14 +64,50 @@
 double logtenoftwo;
 extern short check_bits[];
 
+/* sr.c */
+void do_sr(int, char **, char *, int);
+void rescale(int);
+void drawmark(Window, int, int, int, int);
+void dolabel(Window, int, int, char *, int, int);
+void drawframe(void);
+void doscale(Window, int, int, int, int);
+void dotriangular(Window, int, int, int, int, double (*fun)(double));
+void dotenths(Window, int, int, int, int, char *, int, double, double);
+void drawslide(void);
+void redrawslide(int, int, int, int);
+void redrawframe(int, int, int, int);
+void drawhairl(void);
+void drawnums(void);
 
+/* xcalc.c */
+void parse_double(char *, char *, double *);
+void Syntax(void);
+void XCalcError(char *, char *, char *, char *, char *);
+void SetupTICalc(void);
+void SetupHPCalc(void);
+void DrawDisplay(void);
+void DrawKey(int);
+void InvertKey(int);
+void LetGoKey(int);
+void Quit(void);
+void PushOp(int);
+int PopOp(void);
+int isopempty(void);
+void PushNum(double);
+double PopNum(void);
+void RollNum(int);
+int isnumempty(void);
+void ClearStacks(void);
+int priority(int);
+void ResetCalc(void);
+void TypeChar(char);
+void onalarm(int);
+void Timer(long);
+void set_sizehint(XSizeHints *, int, int, char *);
 
 /**************/
-do_sr(argc, argv, geom, border)
+void do_sr(int argc, char **argv, char *geom, int border)
 /**************/
-char	**argv;
-char	*geom;
-int	border;
 {
     XSizeHints szhint;
     Atom wprot, wdelw;
@@ -147,7 +184,8 @@
 
     while (1) {
         Window wind,mwid;
-	int	dummy, w;
+	int	dummy;
+	unsigned int dummy_u, w;
 
         XNextEvent(dpy, &event);
 
@@ -158,8 +196,8 @@
             wind = exp_event->window;
 
             if (wind==theWindow) {
-		XGetGeometry(dpy, theWindow, &mwid, &dummy, &dummy, &w, &dummy,
-			     &dummy, &dummy);
+		XGetGeometry(dpy, theWindow, &mwid, &dummy, &dummy, &w, &dummy_u,
+			     &dummy_u, &dummy_u);
 		if (width != w) {
 		    rescale(w);
 		    break;
@@ -226,7 +264,8 @@
 	  }
 	case MotionNotify: {
             XPointerMovedEvent *mov_event = (XPointerMovedEvent *) &event;
-	    int	x, y, newx, dummy, mask;
+	    int	x, y, newx, dummy;
+	    unsigned int mask;
 	    Window mwid;
 
             mwid = wind = mov_event->window;
@@ -302,25 +341,24 @@
 		exit(0);
 	    break;
         default:
-           printf("event type=%ld\n",event.type); 
+           printf("event type=%d\n",event.type); 
 
         }  /* end of switch */
     }  /* end main loop */
 }
 
 
-rescale(w)
-int	w;
+void rescale(int w)
 {
-    int	x,y,wx,wy;
+    int	x,y,wx,wy, dummy;
     Window win;
-    int	oldwidth, dummy;
+    unsigned int	oldwidth, dummy_u;
 
-    XGetGeometry(dpy, theWindow, &win, &wx, &wy, &oldwidth, &dummy,
-		 &dummy, &dummy);
+    XGetGeometry(dpy, theWindow, &win, &wx, &wy, &oldwidth, &dummy_u,
+		 &dummy_u, &dummy_u);
     if (oldwidth != w) {
 	XQueryPointer(dpy, theWindow, &win, &win, &dummy, &dummy, &x, &y,
-		      &dummy);
+		      &dummy_u);
 	XMoveResizeWindow(dpy, theWindow, wx + x - (x * w)/oldwidth, wy,
 			  w, HEIGHT);
     }
@@ -332,30 +370,24 @@
     XResizeWindow(dpy, blackwid, width, SLIDEHIGH+2);
     if (framePix)
       XFreePixmap(dpy, framePix);
-    framePix = NULL;
+    framePix = 0;
     drawframe();
     if (slidePix)
       XFreePixmap(dpy, slidePix);
-    slidePix = NULL;
+    slidePix = 0;
     drawslide();
     XMoveWindow(dpy, slidewid, xo, SLIDETOP);
     drawnums();
     drawhairl();
 }
 
-drawmark(win, x, y, height, topp)
-Window	win;
-int	x,y,height,topp;
+void drawmark(Window win, int x, int y, int height, int topp)
 {
     XDrawLine(dpy, win, sgc, x, (topp?y:y+MAJORH-height),
 	      x, height + (topp?y:y+MAJORH-height));
 }
 
-dolabel(win, x, y, str, topp, majorp)
-Window	win;
-int	x,y;
-char	*str;
-int	topp,majorp;
+void dolabel(Window win, int x, int y, char *str, int topp, int majorp)
 {
     XDrawString(dpy, win, sgc, x + 2,
 		(topp?y+FOFFSET+foffset:y+MAJORH-fheight+foffset),
@@ -363,13 +395,13 @@
 }
 
 
-drawframe()
+void drawframe(void)
 {
     int		i,x,j,xx;
     char	str[5];
     int midpt = scalelen/2;
 
-    if (framePix == NULL)
+    if (framePix == 0)
       framePix = XCreatePixmap (dpy, theWindow, width, HEIGHT, 
 				DefaultDepth (dpy, DefaultScreen (dpy)));
     XFillRectangle(dpy, framePix, cgc, 0, 0, width, HEIGHT);
@@ -403,9 +435,7 @@
     XCopyArea(dpy, framePix, theWindow, sgc, 0, 0, scalelen + START+END, HEIGHT, 0, 0);
 }
 
-doscale(win, high, offset, len, topp)
-     Window	win;
-     int	high, offset, len, topp;
+void doscale(Window win, int high, int offset, int len, int topp)
 {
   int	i,x,xx,j;
   int	xs[11];
@@ -430,10 +460,7 @@
   drawmark(win, xs[i], high, MAJORH, topp);
 }
 
-dotriangular(win, high, offset, len, topp, fun)
-Window	win;
-int	high, offset, len, topp;
-double	(*fun)();
+void dotriangular(Window win, int high, int offset, int len, int topp, double (*fun)(double))
 {
     double d, val;
     int i;
@@ -483,12 +510,8 @@
 }
 
 
-dotenths(win, high, offset, len, thislen, str, topp, start, incr)
-Window	win;
-int	high, offset, len, thislen;
-char	*str;
-int	topp;
-double	start, incr;
+void dotenths(Window win, int high, int offset, int len, int thislen,
+	      char *str, int topp, double start, double incr)
 {
     int	i;
     double d;
@@ -540,13 +563,13 @@
 
 
 
-drawslide()
+void drawslide(void)
 {
     int		i,x,j;
     char	str[5];
     int 	midpt = scalelen/2;
 
-    if (slidePix == NULL)
+    if (slidePix == 0)
       slidePix = XCreatePixmap (dpy, theWindow, width, SLIDEHIGH, 
 			        DefaultDepth (dpy, DefaultScreen (dpy)));
     XFillRectangle(dpy, slidePix, cgc, 0, 0, width, SLIDEHIGH);
@@ -565,35 +588,33 @@
     XCopyArea(dpy, slidePix, slidewid, sgc, 0, 0, scalelen+START+END, SLIDEHIGH, 0, 0);
 }
 
-redrawslide(x, y, w, h)
-int	x,y,w,h;
+void redrawslide(int x, int y, int w, int h)
 {
     int	i;
 
-    if (slidePix != NULL)
+    if (slidePix != 0)
       XCopyArea(dpy, slidePix, slidewid, sgc, 0, 0, scalelen + START + END, SLIDEHIGH,
 		0, 0);
     else
       drawslide();
 }
 
-redrawframe(x, y, w, h)
-int	x,y,w,h;
+void redrawframe(int x, int y, int w, int h)
 {
-    if (framePix != NULL)
+    if (framePix != 0)
       XCopyArea(dpy, framePix, theWindow, sgc, 0, 0, scalelen + START + END, HEIGHT,
 		0, 0);
     else
       drawframe();
 }
 
-drawhairl()
+void drawhairl(void)
 {
     XMoveWindow(dpy, hairlwid, hx, 0);
     XClearWindow(dpy, hairlwid);
 }
 
-drawnums()
+void drawnums(void)
 {
     char	str[20];	/* leave room for sprintf to slop over */
     float	x = ((float) (hx - START))/((float) scalelen);
