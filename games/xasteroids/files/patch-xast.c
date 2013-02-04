--- xast.c.orig
+++ xast.c
@@ -3,6 +3,13 @@
 	goetz@cs.buffalo.EDU
 	Version 5, 9 Feb 93
 
+	Changes after version 5.0:
+        
+		Improved cursor-hiding.
+		Arrow keys.
+		ANSI-C cleanups.
+		Use usleep() instead of a delay loop, when available.
+
 	Changes from version 4.3:
 
 		High score script.
@@ -27,16 +34,30 @@
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
@@ -68,10 +89,10 @@
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
@@ -121,6 +142,7 @@
 	shapesize[LASTSHAPE+1]	= {44, 21, 10, 2, 1, SHIPSIZE+1, 35, 20},
 	shield_on;
 
+void
 initasts()
 {	int i;
 	extern Objtype obj[SHIP+1];
@@ -143,6 +165,7 @@
 		obj[i].mass = M_BULLET;
 }	}
 
+void
 makeasts()
 {	int i;
 	extern Objtype obj[SHIP+1];
@@ -163,7 +186,7 @@
 		if (a >  63)
 			obj[i].y = (double) a;
 			else obj[i].y = (double) height - a;
-		a = rand(rndint); a = 4 - a>>5;
+		a = rand(rndint); a = 4 - (a>>5);
 		obj[i].rot = (double) a;
 		a = rand(rndint);
 		obj[i].rotvel = ((double) a)/2048;
@@ -177,6 +200,7 @@
 	numasts = i;
 }
 
+void
 makeenemy()	/* Start an enemy ship	*/
 {	extern Objtype obj[SHIP+1];
 	extern int height, level, rndint;
@@ -258,6 +282,7 @@
 	return 0;
 }
 
+void
 blastpair(i, j)		/* Generate random velocity vector v.	*/
 	int i, j ;	/* Add v to i, -v to j.			*/
 {	extern int rndint;
@@ -266,7 +291,7 @@
 	double vx, vy;
 	c = rand(rndint);
 /*	c = 4 - c>>5;	if you need angles from -3 to 4		*/
-	c>>2;		/* possibly save some time on sin/cos	*/
+	c >>= 2;		/* possibly save some time on sin/cos	*/
 	vx = cos((double) c); vy = sin((double) c);
 	obj[i].xvel = obj[i].xvel + vx;
 	obj[i].yvel = obj[i].yvel + vy;
@@ -282,6 +307,7 @@
 #define rotinert(i)	(double) (obj[i].mass*shapesize[obj[i].shape]*shapesize[obj[i].shape])
 
 /* cause two objects to collide elastically	*/
+void
 bounce(i, j)
 int	i,j;
 {
@@ -345,6 +371,7 @@
 obj[j].rotvel = temp;
 }
 
+void
 botline(disp, window, gc)	/* Print status line text	*/
 	Display *disp;
 	Drawable window;
@@ -357,6 +384,7 @@
 			text, strlen(text));
 }
 
+void
 printss(disp, window, gc)	/* Print ships and score	*/
 	Display *disp;
 	Drawable window;
@@ -389,6 +417,7 @@
 	XClearArea(disp, window, 340+(energy>>1), height+8, 8, 10, False);
 }
 
+void
 upscore(killer, up)	/* Only award score for things the player shot */
 	int killer, up;
 {	extern int score;
@@ -397,6 +426,7 @@
 }
 
 /* boom, movebooms, drawbooms all by Peter Phillips */
+void
 boom(ob, particles, duration)
 int ob;
 int particles;
@@ -429,6 +459,7 @@
 }
 
 /* move the various booms that are active */
+void
 movebooms()
 {
   int i;
@@ -461,6 +492,7 @@
 }
 
 /* Draw the various booms */
+void
 drawbooms(disp, window, gc)
      Display *disp;
      Drawable window;
@@ -481,6 +513,7 @@
   }
 }
 
+void
 deletebooms()	/* delete all booms */
 {	Boom b;
 
@@ -490,11 +523,12 @@
 		b = b->next;
 }	}
 
+void
 killast(killer, i)
 	int killer, i;		/* i = Asteroid # to kill	*/
 {	extern Objtype obj[SHIP+1];
 	extern int numasts;
-	int k, na, oldna;
+	int k, na = 0, oldna;
 
 	if (obj[i].shape == ASTSHAPE1)
 	{	na = nextast();		/* Could put 6 lines in a sub */
@@ -543,6 +577,8 @@
 	{	boom(i, 9, 7);
 		obj[i].alive = 0; upscore(killer, 500);}
 }
+
+void
 moveobjs(crash)
 	int *crash;
 {	extern Objtype obj[SHIP+1];
@@ -585,6 +621,7 @@
 	    }
 }
 
+void
 fire()
 {	extern Objtype obj[SHIP+1];
 	extern int width, nextbul;
@@ -603,6 +640,7 @@
 	nextbul++; if (nextbul == LASTBUL+1) nextbul = FBUL;
 }
 
+void
 hyper()
 {	extern Objtype obj[SHIP+1];
 	extern int width, height, rndint;
@@ -617,6 +655,7 @@
 	obj[SHIP].y = (double) i;
 }
 
+void
 vdraw(disp, window, gc, shape, x, y, rot)
 	Display *disp;
 	Drawable window;
@@ -639,6 +678,7 @@
 	XDrawLines (disp, window, gc, figure, numpairs[shape], CoordModePrevious);
 }
 
+int
 main(argc, argv)
 	int argc;
 	char **argv;
@@ -663,8 +703,8 @@
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
@@ -704,11 +744,30 @@
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
@@ -746,7 +805,7 @@
 		{   XNextEvent(disp, &event);
 		    switch (event.type)
 		    {	case MappingNotify:
-			    XRefreshKeyboardMapping (&event);
+			    XRefreshKeyboardMapping ((XMappingEvent *)&event);
 			    break;
 			case ConfigureNotify:
 			    width = event.xconfigure.width;
@@ -757,28 +816,29 @@
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
@@ -787,52 +847,55 @@
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
@@ -850,7 +913,7 @@
 			    botline(disp, window, gc);
 			}
 			/* Write copyright notice	*/
-			if (!ships && blist == NULL)
+			if (!ships)
 			{   sprintf(text, "Xasteroids");
 			    XDrawImageString (disp, pixmap, gc,
 				width/2-50, height/2-2*letheight,
@@ -917,7 +980,11 @@
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
