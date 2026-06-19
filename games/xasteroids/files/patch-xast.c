--- xast.c.orig	2026-06-19 11:03:44 UTC
+++ xast.c
@@ -3,6 +3,14 @@
 	goetz@cs.buffalo.EDU
 	Version 5, 9 Feb 93
 
+	Changes after version 5.0:
+        
+		Improved cursor-hiding.
+		Arrow keys.
+		ANSI-C cleanups.
+		Use usleep() instead of a delay loop, when available.
+		Add prototypes.
+
 	Changes from version 4.3:
 
 		High score script.
@@ -27,16 +35,30 @@
 			Pat Ryan <pat@jaameri.gsfc.nasa.gov>
 			Craig Smith <csmith@cscs.UUCP>
 			Doug Merritt <doug@netcom.com>
+			Stephen McCamant <alias@mcs.com>
 			Makefile by James Berg <berg@plains>
 			Hi score script by Chris Moore <moore@src.bae.co.uk>
 			Man page by David Partain <dpl@ida.liu.se>
 */
 #include <stdio.h>		/* For NULL	*/
+#include <stdlib.h>		/* For malloc(), rand() etc */
+#include <string.h>		/* For srtlen() */
+#include <time.h>		/* For time() */
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#include <X11/cursorfont.h>	/* For erasing cursor - not important	*/
+#include <X11/keysym.h>
 #include <math.h>
 
+#ifdef HAS_USLEEP
+#include <unistd.h>
+#endif
+
+#ifndef __STDC__
+define void
+#endif
+
+#define rand(rndint) rand() /* ??? */
+
 /* Indexes for 1st dimension of obj	*/
 /* The order they are in is important	*/
 #define	AST	0
@@ -68,10 +90,10 @@
 #define M_BULLET 0.1
 
 /* Keys		*/
-#define FIRE		'p'
-#define PAUSE		27	/* escape	*/
-#define SHIELD		'`'
-#define THRUST		'o'
+#define FIRE		XK_p
+#define PAUSE		XK_Escape	/* escape	*/
+#define SHIELD		XK_grave	/* ` */
+#define THRUST		XK_o
 
 #define BMAX		300	/* Max particles in a "boom" + 1	*/
 #define letheight	20	/* height of font	*/
@@ -121,6 +143,7 @@ int	width, height,
 	shapesize[LASTSHAPE+1]	= {44, 21, 10, 2, 1, SHIPSIZE+1, 35, 20},
 	shield_on;
 
+void
 initasts()
 {	int i;
 	extern Objtype obj[SHIP+1];
@@ -143,6 +166,7 @@ initasts()
 		obj[i].mass = M_BULLET;
 }	}
 
+void
 makeasts()
 {	int i;
 	extern Objtype obj[SHIP+1];
@@ -163,7 +187,7 @@ makeasts()
 		if (a >  63)
 			obj[i].y = (double) a;
 			else obj[i].y = (double) height - a;
-		a = rand(rndint); a = 4 - a>>5;
+		a = rand(rndint); a = 4 - (a>>5);
 		obj[i].rot = (double) a;
 		a = rand(rndint);
 		obj[i].rotvel = ((double) a)/2048;
@@ -177,6 +201,7 @@ makeasts()
 	numasts = i;
 }
 
+void
 makeenemy()	/* Start an enemy ship	*/
 {	extern Objtype obj[SHIP+1];
 	extern int height, level, rndint;
@@ -199,9 +224,9 @@ int nextast()	/* Find next unused asteroid object	*/
 	return i;
 }
 
-int collide(i, j)	/* Returns non-zero if i collided with j	*/
+int collide(int i, int j)
+			/* Returns non-zero if i collided with j	*/
 			/* Ship must be j!  (See below)			*/
-	int i, j;
 {	extern Objtype obj[SHIP+1];
 	extern int shapesize[LASTSHAPE+1];
 	extern double drawscale;
@@ -258,15 +283,17 @@ Loopend:		jx1 = jx2; jy1 = jy2;
 	return 0;
 }
 
-blastpair(i, j)		/* Generate random velocity vector v.	*/
-	int i, j ;	/* Add v to i, -v to j.			*/
+void
+blastpair(int i, int j)
+			/* Generate random velocity vector v.	*/
+			/* Add v to i, -v to j.			*/
 {	extern int rndint;
 	extern Objtype obj[SHIP+1];
 	unsigned char c;	/* for rand	*/
 	double vx, vy;
 	c = rand(rndint);
 /*	c = 4 - c>>5;	if you need angles from -3 to 4		*/
-	c>>2;		/* possibly save some time on sin/cos	*/
+	c >>= 2;		/* possibly save some time on sin/cos	*/
 	vx = cos((double) c); vy = sin((double) c);
 	obj[i].xvel = obj[i].xvel + vx;
 	obj[i].yvel = obj[i].yvel + vy;
@@ -282,8 +309,8 @@ blastpair(i, j)		/* Generate random velocity vector v.
 #define rotinert(i)	(double) (obj[i].mass*shapesize[obj[i].shape]*shapesize[obj[i].shape])
 
 /* cause two objects to collide elastically	*/
-bounce(i, j)
-int	i,j;
+void
+bounce(int i, int j)
 {
 double	rotrat, temp;
 extern	Objtype obj[SHIP+1];
@@ -345,10 +372,9 @@ obj[j].rotvel = temp;
 obj[j].rotvel = temp;
 }
 
-botline(disp, window, gc)	/* Print status line text	*/
-	Display *disp;
-	Drawable window;
-	GC gc;
+void
+botline(Display *disp, Drawable window, GC gc)
+			/* Print status line text	*/
 {	extern int highscore, ships, score;
 	char text[70];
 	sprintf(text, "Ships:%2d   Score:%6d   Shield:        High:%6d",
@@ -357,10 +383,9 @@ botline(disp, window, gc)	/* Print status line text	*/
 			text, strlen(text));
 }
 
-printss(disp, window, gc)	/* Print ships and score	*/
-	Display *disp;
-	Drawable window;
-	GC gc;
+void
+printss(Display *disp, Drawable window, GC gc)
+			/* Print ships and score	*/
 {	extern int height, highscore, oldscore, ships, score;
 	extern Objtype obj[SHIP+1];	/* to kill ship	*/
 	char sstring[30];
@@ -389,18 +414,17 @@ printss(disp, window, gc)	/* Print ships and score	*/
 	XClearArea(disp, window, 340+(energy>>1), height+8, 8, 10, False);
 }
 
-upscore(killer, up)	/* Only award score for things the player shot */
-	int killer, up;
+void
+upscore(int killer, int up)
+		/* Only award score for things the player shot */
 {	extern int score;
 	if (killer != ENEMYBUL && killer != SHIP)
 		score = score + up;
 }
 
 /* boom, movebooms, drawbooms all by Peter Phillips */
-boom(ob, particles, duration)
-int ob;
-int particles;
-int duration;
+void
+boom(int ob, int particles, int duration)
 { extern int rndint;
   int i;
   unsigned int r1, r2;
@@ -429,6 +453,7 @@ int duration;
 }
 
 /* move the various booms that are active */
+void
 movebooms()
 {
   int i;
@@ -461,10 +486,8 @@ movebooms()
 }
 
 /* Draw the various booms */
-drawbooms(disp, window, gc)
-     Display *disp;
-     Drawable window;
-     GC gc;
+void
+drawbooms(Display *disp, Drawable window, GC gc)
 {
   int i;
   Boom b;
@@ -481,6 +504,7 @@ drawbooms(disp, window, gc)
   }
 }
 
+void
 deletebooms()	/* delete all booms */
 {	Boom b;
 
@@ -490,11 +514,11 @@ deletebooms()	/* delete all booms */
 		b = b->next;
 }	}
 
-killast(killer, i)
-	int killer, i;		/* i = Asteroid # to kill	*/
+void
+killast(int killer, int i)	/* i = Asteroid # to kill	*/
 {	extern Objtype obj[SHIP+1];
 	extern int numasts;
-	int k, na, oldna;
+	int k, na = 0, oldna;
 
 	if (obj[i].shape == ASTSHAPE1)
 	{	na = nextast();		/* Could put 6 lines in a sub */
@@ -543,8 +567,9 @@ killast(killer, i)
 	{	boom(i, 9, 7);
 		obj[i].alive = 0; upscore(killer, 500);}
 }
-moveobjs(crash)
-	int *crash;
+
+void
+moveobjs(int *crash)
 {	extern Objtype obj[SHIP+1];
 	extern int ships;
 	extern double speedscale;
@@ -585,6 +610,7 @@ moveobjs(crash)
 	    }
 }
 
+void
 fire()
 {	extern Objtype obj[SHIP+1];
 	extern int width, nextbul;
@@ -603,6 +629,7 @@ fire()
 	nextbul++; if (nextbul == LASTBUL+1) nextbul = FBUL;
 }
 
+void
 hyper()
 {	extern Objtype obj[SHIP+1];
 	extern int width, height, rndint;
@@ -617,13 +644,9 @@ hyper()
 	obj[SHIP].y = (double) i;
 }
 
-vdraw(disp, window, gc, shape, x, y, rot)
-	Display *disp;
-	Drawable window;
-	GC gc;
-	int shape;
-	double x, y, rot;
-
+void
+vdraw(Display *disp, Drawable window, GC gc,
+    int shape, double x, double y, double rot)
 {	int line;
 	extern PolarPair shapes[LASTSHAPE+1][11];
 	extern int numpairs[LASTSHAPE+1];
@@ -639,9 +662,8 @@ vdraw(disp, window, gc, shape, x, y, rot)
 	XDrawLines (disp, window, gc, figure, numpairs[shape], CoordModePrevious);
 }
 
-main(argc, argv)
-	int argc;
-	char **argv;
+int
+main(int argc, char *argv[])
 {	Colormap cmap;
 	Cursor cursor;
 	Display *disp;
@@ -663,8 +685,8 @@ main(argc, argv)
 	extern int level, numasts, rndint, ships, score, oldscore;
 	extern Objtype obj[SHIP+1];
 	unsigned char c;	/* for rand	*/
-	double *temp, dx, dy, dist;
-	int crashed, flashon, len, pause = 0, delay = 64,
+	double dx, dy, dist;
+	int crashed, flashon, pause = 0, delay = 64,
 		enemycount, counter, counterstart = 1,
 		i,	/* index for drawing objs, counting bullets */
 		r;	/* radius of shield circle	*/
@@ -704,11 +726,30 @@ main(argc, argv)
 		KeyPressMask | KeyReleaseMask | StructureNotifyMask);
 	XMapRaised (disp, window);
 
-	/* Erase cursor. Just delete next 5 lines if any error.	*/
+	/* Make cursor invisible. Just delete chunk if any error.	*/
 	cmap = XDefaultColormap(disp, screen);
 	XAllocNamedColor(disp, cmap, "Black", &exact, &black);
+#if 0   /* Easy way, but can leave a black spot */
+#include <X11/cursorfont.h>
 	cursor = XCreateFontCursor(disp, XC_dot);
 	XRecolorCursor(disp, cursor, &black, &black);
+#else   /* Hard, good way */
+	{	unsigned wd, ht;
+		Pixmap pm, maskpm;
+		GC cleargc;
+		XQueryBestCursor(disp, window, 1, 1, &wd, &ht);
+		pm = XCreatePixmap(disp, window, wd, ht, 1);
+		maskpm = XCreatePixmap(disp, window, wd, ht, 1);
+		cleargc = XCreateGC(disp, pm, 0, 0);
+		XFillRectangle(disp, pm, cleargc, 0, 0, wd, ht); 
+		XFillRectangle(disp, maskpm, cleargc, 0, 0, wd, ht); 
+		cursor = XCreatePixmapCursor(disp, pm, maskpm, 
+						&black, &black, 1, 1);
+		XFreePixmap(disp, pm);
+		XFreePixmap(disp, maskpm);
+		XFreeGC(disp, cleargc);
+	}
+#endif
 	XDefineCursor(disp, window, cursor);
 
 	XFillRectangle (disp, pixmap, pmgc, 0, 0, width, height);
@@ -746,7 +787,7 @@ Newship:    botline(disp, window, gc);
 		{   XNextEvent(disp, &event);
 		    switch (event.type)
 		    {	case MappingNotify:
-			    XRefreshKeyboardMapping (&event);
+			    XRefreshKeyboardMapping ((XMappingEvent *)&event);
 			    break;
 			case ConfigureNotify:
 			    width = event.xconfigure.width;
@@ -757,28 +798,29 @@ Newship:    botline(disp, window, gc);
 			    botline(disp, window, gc);
 			    break;
 			case KeyPress:
-			    len = XLookupString (&event, text, 10, &key, 0);
-			    if (len == 1 && !shield_on) switch (text[0])
-			    {	case 'e':
+			    key = XLookupKeysym ((XKeyEvent *)&event, 0);
+			    if (!shield_on) switch (key)
+			    {	case XK_Left: case XK_e:
 				    obj[SHIP].rotvel = obj[SHIP].rotvel - .1; break;
-				case 'r':
+				case XK_Right: case XK_r:
 				    obj[SHIP].rotvel = obj[SHIP].rotvel + .1; break;
-				case 'w':
+				case XK_w:
 				    obj[SHIP].rot -= pi/4; break;
-				case 't':
+				case XK_t:
 				    obj[SHIP].rot += pi/4; break;
-				case 'd':
+				case XK_d:
 				    obj[SHIP].rotvel = obj[SHIP].rotvel - .02; break;
-				case 'f':
+				case XK_f:
 				    obj[SHIP].rotvel = obj[SHIP].rotvel + .02; break;
-				case THRUST:
+				case XK_Up: case THRUST:
 				    obj[SHIP].xvel += cos(obj[SHIP].rot);
 				    obj[SHIP].yvel += sin(obj[SHIP].rot);
 				    obj[SHIP].shape = SHIPTHRSHAPE;
 				    break;
+				case XK_Control_L: case XK_Control_R:
 				case FIRE:
 				    if (obj[SHIP].alive) fire(); break;
-				case ' ':
+				case XK_space:
 				    if (obj[SHIP].alive)
 				    {	hyper(); flashon = 1;
 /*				    NOT XSetForeground (disp, gc, bg);
@@ -787,52 +829,55 @@ Newship:    botline(disp, window, gc);
 					XFillRectangle (disp, pixmap, pmgc, 0, 0, width, height);
 				    }
 				    break;
-				case SHIELD:
+				case XK_Down: case SHIELD:
 				    if (energy)
 				    {	shield_on = 1;
 					obj[SHIP].shape = SHIPSHAPE;}
 					break;
-				case '.':	/* decrease delay	*/
+				case XK_period:	/* decrease delay	*/
 				    if (delay > 1) delay >>=1; break;
-				case ',':	/* increase delay	*/
+				case XK_comma:	/* increase delay	*/
 				    delay <<=1; break;
-				case 'm':	/* decrease drawscale - may go negative */
+				case XK_m:	/* decrease drawscale - may go negative */
 				    drawscale -= .1; break;
-				case 'n':	/* increase drawscale	*/
+				case XK_n:	/* increase drawscale	*/
 				    drawscale += .1; break;
-				case '2':	/* increase speedscale	*/
+				case XK_2:	/* increase speedscale	*/
 				    speedscale += .1; break;
-				case '1':	/* decrease speedscale	*/
+				case XK_1:	/* decrease speedscale	*/
 				    speedscale -= .1; break;
-				case 'b':	/* increase moves/update */
+				case XK_b:	/* increase moves/update */
 				    counterstart++; break;
-				case 'v':	/* decrease moves/update */
+				case XK_v:	/* decrease moves/update */
 				    if (counterstart > 1) counterstart--;
 				    break;
 				case PAUSE:	/* pause	*/
 				    pause = 1 - pause; break;
-				case '+':	/* cheat	*/
+				case XK_plus:	/* cheat	*/
 				    ships++; botline(disp, window, gc); break;
-				case 'Q':	/* quit		*/
-				    goto End;
-				case 's':	/* start new ship */
-				    if (!obj[SHIP].alive)
+				case XK_q:	/* quit		*/
+				    if (event.xkey.state & ShiftMask)
+					goto End;
+				    break;
+				case XK_s:	/* start new ship */
+				    if (!obj[SHIP].alive) {
 					if (ships < 1) goto Newgame;
 					else goto Newship;
+				    }
 				    break;
 			    }
 			    break;
 			case KeyRelease:
-			    len = XLookupString(&event, text, 10, &key, 0);
-			    if (len == 1) switch (text[0])
-			    {	case 'e':
+			    key = XLookupKeysym((XKeyEvent *)&event, 0);
+			    switch (key)
+			    {	case XK_Left: case XK_e:
 				    obj[SHIP].rotvel = 0; break;
-				case 'r':
+				case XK_Right: case XK_r:
 				    obj[SHIP].rotvel = 0; break;
-				case THRUST:
+				case XK_Up: case THRUST:
 				    obj[SHIP].shape = SHIPSHAPE;
 				    break;
-				case SHIELD:
+				case XK_Down: case SHIELD:
 				    shield_on = 0; break;
 			    }
 /*			    break;		*/
@@ -850,7 +895,7 @@ Newship:    botline(disp, window, gc);
 			    botline(disp, window, gc);
 			}
 			/* Write copyright notice	*/
-			if (!ships && blist == NULL)
+			if (!ships)
 			{   sprintf(text, "Xasteroids");
 			    XDrawImageString (disp, pixmap, gc,
 				width/2-50, height/2-2*letheight,
@@ -917,7 +962,11 @@ Newship:    botline(disp, window, gc);
 			}
 			else	obj[ENEMYBUL].alive = 0;
 		    }
+#ifdef HAS_USLEEP
+		    usleep(delay);
+#else
 		    for (i = 0; i < delay; i++);
+#endif
 		}
 	    }
 	}
