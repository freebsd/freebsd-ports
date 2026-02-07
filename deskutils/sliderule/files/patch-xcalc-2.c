--- xcalc.c.orig	2024-10-19 09:24:45.430740000 +0200
+++ xcalc.c	2024-10-22 23:27:45.340336000 +0200
@@ -4,7 +4,7 @@
 
 #ifndef lint
 static char *rcsid_xcalc_c = "$XConsortium: xcalc.c,v 1.23 88/10/05 11:13:33 jim Exp $";
-#endif	lint
+#endif	/* lint */
 
 /*
  * xcalc.c  -  a hand calculator for the X Window system
@@ -34,6 +34,7 @@
 
 #include <errno.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 #include <signal.h>
 #include <X11/Xos.h>
@@ -113,11 +114,11 @@
 struct _key {
            char   *st;
 	   int	  code;
-	   int    (*fun)();
+	   void    (*fun)(int);
            Window wid;
            short  x,y,width,height;
            int    fore,back;
-	   void	  (*func)();
+	   void	  (*func)(void);
             };
 
 struct _key *key;
@@ -171,9 +172,67 @@
 #define kBKSP  46
 
 
-int  oneop(),twoop(),clearf(),offf(),invf(),drgf(),eef();
-int  lparf(),rparf(),digit(),decf(),negf(),equf();
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
+void XCalcError(char *, char *);
+void SetupTICalc(void);
+void SetupHPCalc(void);
+void DrawDisplay(void);
+void DrawKey(int);
+void InvertKey(int);
+void LetGoKey(int);
+void digit(int);
+void bkspf(int);
+void decf(int);
+void eef(int);
+void clearf(int);
+void negf(int);
+void twoop(int);
+void twof(int);
+void entrf(int);
+void equf(int);
+void lparf(int);
+void rollf(int);
+void rparf(int);
+void drgf(int);
+void invf(int);
+void memf(int);
+void oneop(int);
+void offf(int);
+void nop(int);
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
+void fperr(int);
+void set_sizehint(XSizeHints *, int, int, char *);
+
 /* "1/x", "x^2", "SQRT","CE/C", "AC",
    "INV", "sin", "cos", "tan",  "DRG",
    "e",   "EE",  "log", "ln",   "y^x",
@@ -201,8 +260,6 @@
   {"EXC",kEXC,oneop},{"0",kZERO,digit},{".",kDEC,decf},
   {"+/-",kNEG,negf},{"=",kEQU,equf}};
 
-int  twof(),nop(),rollf(),bkspf(),entrf(),memf();
-
 /*  { "SQRT","e^x", "10^x", "y^x", "1/x", "CHS", "7", "8", "9",  "/",
       "x!",  "PI",  "sin",  "cos", "tan", "EEX", "4", "5", "6",  "x",
       "",    "",    "R v",  "x:y", "<-",  "ENTR","1", "2", "3",  "-",
@@ -247,10 +304,7 @@
  * sscanf will call lower level routines that will set errno.
  */
 
-void parse_double (src, fmt, dp)
-    char *src;
-    char *fmt;
-    double *dp;
+void parse_double (char *src, char *fmt, double *dp)
 {
     int olderrno = errno;
 
@@ -265,9 +319,7 @@
  * fetched before the display is open.  The program should get rewritten....
  */
 
-static void open_the_display (argc, argv)
-    int argc;
-    char **argv;
+static void open_the_display (int argc, char **argv)
 {
     int i;
     char *displayname = NULL;
@@ -296,15 +348,10 @@
 
 
 /**************/
-main(argc, argv)
-    int   argc;
-    char *argv[];
+int main(int argc, char **argv)
 /**************/
 {
     int i, status,dpcs;
-#ifndef IEEE
-    extern void fperr();
-#endif
 
     char *fc, *bc, *nfc, *nbc, *ofc, *obc, *ffc, *fbc, *dfc, *dbc, *ifc, *ibc;
     char *geom    = NULL;
@@ -529,7 +576,7 @@
 
     /* Create Icon Pixmap */
     IconPix = XCreateBitmapFromData (dpy, DefaultRootWindow(dpy),
-        icon_bits, icon_width, icon_height);
+        (char *)icon_bits, icon_width, icon_height);
 
     if (analog)
       do_sr(argc, argv, geom, border);
@@ -550,7 +597,7 @@
 				    szhint.x, szhint.y, 
 			    	    szhint.width, szhint.height, border,
 				    ForeColor, BackColor);
-    if (!theWindow) XCalcError("Can't open calculator window");
+    if (!theWindow) XCalcError("Can't open calculator window", NULL);
 
     if (stip)
       XSetWindowBackgroundPixmap(dpy, theWindow, backgroundPix);
@@ -687,7 +734,7 @@
             break;
 	  }
         default:
-            fprintf (stderr, "%s:  unexpected event type %ld = 0x%lx\n",
+            fprintf (stderr, "%s:  unexpected event type %d = 0x%x\n",
 	   	    ProgramName, event.type, event.type);
 	    break;
         }  /* end of switch */
@@ -696,7 +743,7 @@
 
 
 /***********************************/
-Syntax ()
+void Syntax (void)
 {
     fprintf (stderr, "usage:  %s [-options ...]\n\n",
 	     ProgramName);
@@ -722,17 +769,16 @@
 
 
 /***********************************/
-XCalcError(identifier,arg1,arg2,arg3,arg4)
-       char *identifier,*arg1,*arg2,*arg3,*arg4;
+void XCalcError(char *identifier, char *arg1)
 {
-    fprintf(stderr, identifier, arg1,arg2,arg3,arg4);
+    fprintf(stderr, identifier, arg1);
     exit(1);
 }
 
 
 
 /***********************************/
-SetupTICalc()
+void SetupTICalc(void)
 {
     int i;
 
@@ -773,7 +819,7 @@
 				  dispwide-2,disphigh,2,DispFore,DispBack);
 }
 
-SetupHPCalc()
+void SetupHPCalc(void)
 {
     int i,j;
 
@@ -816,7 +862,7 @@
 
 
 /**************/
-DrawDisplay()
+void DrawDisplay(void)
 {
     int strwide;
 
@@ -855,8 +901,7 @@
 
 
 /***************/
-DrawKey(keynum)
-    int keynum;
+void DrawKey(int keynum)
 {
     char *str;
     int strwide,extrapad;
@@ -876,8 +921,7 @@
 
 
 /*********************************/
-InvertKey(keynum)
-    int keynum;
+void InvertKey(int keynum)
 {
     struct _key *kp;
 
@@ -910,8 +954,7 @@
 static double mem[10] = { 0.0 };
 
 /*********************************/
-LetGoKey(keynum)
-     int keynum;
+void LetGoKey(int keynum)
 {
     int i;
     int code;
@@ -980,8 +1023,7 @@
 }
 
 
-digit(keynum)
-     int keynum;
+void digit(int keynum)
 {
   flagINV=0;
   if (rpn && (memop == kSTO || memop == kRCL || memop == kSUM)) {
@@ -1012,7 +1054,7 @@
   entered=1;
 }
 
-bkspf()
+void bkspf(int dummy)
 {
   if (entered!=1 || clrdisp)
     return;
@@ -1025,7 +1067,7 @@
   DrawDisplay();
 }
 
-decf()
+void decf(int dummy)
 {
   flagINV=0;
   if (clrdisp) {
@@ -1042,7 +1084,7 @@
   entered=1;
 }
 
-eef()
+void eef(int dummy)
 {
   flagINV=0;
   if (clrdisp) {
@@ -1059,7 +1101,7 @@
   entered=1;
 }
 
-clearf()
+void clearf(int dummy)
 {
   flagINV=0;
   if (clear && !rpn) { /* clear all */
@@ -1074,7 +1116,7 @@
   DrawDisplay();
 }
 
-negf()
+void negf(int dummy)
 {
   flagINV=0;
   if (exponent) {       /* neg the exponent */
@@ -1101,10 +1143,8 @@
 }
 
 /* Two operand functions for infix calc */
-twoop(keynum)
+void twoop(int keynum)
 {
-  double PopNum();
-
   if (flagINV) {
     flagINV=0;
     DrawDisplay();
@@ -1166,10 +1206,8 @@
 }                      
 
 /* Two operand functions for rpn calc */
-twof(keynum)
+void twof(int keynum)
 {
-  double PopNum();
-
   if (flagINV) {
     flagINV=0;
     DrawDisplay();
@@ -1196,7 +1234,7 @@
 }
 
 
-entrf()
+void entrf(int dummy)
 {
   flagINV=0;
   if (!entered)
@@ -1213,10 +1251,8 @@
     PushNum(dnum);
 }
 
-equf()
+void equf(int dummy)
 {
-  double PopNum();
-
   flagINV=0;
   if (!entered)
     return;
@@ -1257,7 +1293,7 @@
   DrawDisplay();
 }
         
-lparf()
+void lparf(int dummy)
 {
   flagINV=0;
   PushOp(kLPAR);
@@ -1265,10 +1301,8 @@
   DrawDisplay();
 }
 
-rollf()
+void rollf(int dummy)
 {
-  double PopNum();
-
   if (!entered)
     return;
   if (entered==1)
@@ -1281,10 +1315,8 @@
   DrawDisplay();
 }
 
-rparf()
+void rparf(int dummy)
 {
-  double PopNum();
-
   flagINV=0;
   if (!entered)
     return;
@@ -1326,7 +1358,7 @@
   DrawDisplay();
 }
 
-drgf()
+void drgf(int dummy)
 {
   if (flagINV) {
     if (entered==1)
@@ -1343,7 +1375,8 @@
   }
                          
   flagINV=0;
-  drgmode = ++drgmode % 3;
+  drgmode++;
+  drgmode = drgmode % 3;
   switch (drgmode) {
   case DEG:  drg2rad=PI / 180.0;
 	     rad2drg=180.0 / PI;
@@ -1358,13 +1391,13 @@
   DrawDisplay();
 }
 
-invf()
+void invf(int dummy)
 {
   flagINV = ~flagINV;
   DrawDisplay();
 }
 
-memf(keynum)
+void memf(int keynum)
 {
     if (entered==1)
       parse_double(dispstr,"%lf",&dnum);
@@ -1372,7 +1405,7 @@
     clrdisp++;
 }
 
-oneop(keynum)
+void oneop(int keynum)
 {
   int i,j;
   double dtmp;
@@ -1434,7 +1467,7 @@
   DrawDisplay();
 }
 
-offf()
+void offf(int dummy)
 {
   /* full reset */
   ResetCalc();
@@ -1445,14 +1478,14 @@
 }
 
 
-nop()
+void nop(int dummy)
 {
   XBell(dpy, 0);
 }
 
 
 /*******/
-Quit()
+void Quit(void)
 /*******/
 {
     if (dpy) XCloseDisplay (dpy);
@@ -1468,8 +1501,7 @@
 
 
 /*******/
-PushOp(op)
-   int op;
+void PushOp(int op)
 /*******/
 {
   if (opsp==STACKMAX) {strcpy(dispstr,"stack error");  entered=3;}
@@ -1477,7 +1509,7 @@
 }
 
 /*******/
-int PopOp()
+int PopOp(void)
 /*******/
 {
   if (opsp==0) {
@@ -1489,15 +1521,14 @@
 }
 
 /*******/
-int isopempty()
+int isopempty(void)
 /*******/
 {
   return( opsp ? 0 : 1 );
 }
 
 /*******/
-PushNum(num)
- double num;
+void PushNum(double num)
 /*******/
 {
   if (rpn) {
@@ -1514,7 +1545,7 @@
 }
 
 /*******/
-double PopNum()
+double PopNum(void)
 /*******/
 {
     if (rpn) {
@@ -1532,7 +1563,7 @@
 }
 
 /*******/
-RollNum(dir)
+void RollNum(int dir)
 /*******/
 {
     double tmp;
@@ -1554,7 +1585,7 @@
 
 
 /*******/
-int isnumempty()
+int isnumempty(void)
 /*******/
 {
   return( numsp ? 0 : 1 );
@@ -1562,7 +1593,7 @@
 
 
 /*******/
-ClearStacks()
+void ClearStacks(void)
 /*******/
 {
     if (rpn)
@@ -1572,8 +1603,7 @@
 
 
 /*******/
-int priority(op)
-         int op;
+int priority(int op)
 /*******/
 {
     switch (op) {
@@ -1588,7 +1618,7 @@
 
 
 /********/
-ResetCalc()
+void ResetCalc(void)
 /********/
 {
     flagM=flagK=flagINV=flagE=flagPAREN=0;  drgmode=DEG;
@@ -1600,8 +1630,7 @@
 
 
 /*********/
-TypeChar(c)
-    char c;
+void TypeChar(char c)
 /*********/
 {
     /* figure out if person typed a valid calculator key.
@@ -1678,15 +1707,14 @@
 
 /*******/
 void
-onalarm()
+onalarm(int dummy)
 /*******/
 {
   timerdone=1;
 }
 
 /*******/
-Timer(val)
- long val;
+void Timer(long val)
 /*******/
 {
         struct itimerval it;
@@ -1705,20 +1733,15 @@
 #ifndef IEEE
 /******************/
 void
-fperr(sig,code,scp)
-  int sig,code;
-  struct sigcontext *scp;
+fperr(int sig)
 /******************/
 {
-    longjmp(env,code);
+    longjmp(env,1);
 }
 
 #endif
 
-set_sizehint (hintp, min_width, min_height, geom)
-    XSizeHints *hintp;
-    int min_width, min_height;
-    char *geom;
+void set_sizehint (XSizeHints *hintp, int min_width, int min_height, char *geom)
 {
     int geom_result;
 
@@ -1731,7 +1754,7 @@
     geom_result = NoValue;
     if (geom != NULL) {
         geom_result = XParseGeometry (geom, &hintp->x, &hintp->y,
-				      &hintp->width, &hintp->height);
+				      (unsigned int *)&hintp->width, (unsigned int *)&hintp->height);
 	if ((geom_result & WidthValue) && (geom_result & HeightValue)) {
 	    hintp->width = max (hintp->width, hintp->min_width);
 	    hintp->height = max (hintp->height, hintp->min_height);
