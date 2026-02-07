--- golddig.h.orig	2001-03-19 19:26:10 UTC
+++ golddig.h
@@ -11,43 +11,47 @@
 #ifdef VMS
 #define LIB "GOLDDIG$:" /* Default path name */
 #endif
- 
-int xsize,ysize;        /* Current level width and height */
-int levelstart;         /* Level that player started at */
-int levelnum;           /* Current level number */
-int score;              /* Total score */
-int speed;              /* Speed of game.  1 is slowest, 5 is default */
+
+#ifndef GOLDDIG_EXTERN
+#define GOLDDIG_EXTERN extern
+#endif
+
+GOLDDIG_EXTERN int xsize,ysize;        /* Current level width and height */
+GOLDDIG_EXTERN int levelstart;         /* Level that player started at */
+GOLDDIG_EXTERN int levelnum;           /* Current level number */
+GOLDDIG_EXTERN int score;              /* Total score */
+GOLDDIG_EXTERN int speed;              /* Speed of game.  1 is slowest, 5 is default */
 extern int lives;       /* How many player lives left */
 extern int angelleft;   /* How many movement on angelhood are left */
-int goldleft;           /* Total number of treasure blocks left */
-char *worldname;        /* Name of world (set of levels) */
-int curtick;            /* Current clock tick number */
+GOLDDIG_EXTERN int goldleft;           /* Total number of treasure blocks left */
+GOLDDIG_EXTERN char *worldname;        /* Name of world (set of levels) */
+GOLDDIG_EXTERN int curtick;            /* Current clock tick number */
 extern int newlevel;    /* Non-zero if a new level was just drawn */
-extern int savehighscore; /* only save highscores if only default levels */
+GOLDDIG_EXTERN int savehighscore; /* only save highscores if only default levels */
 			  /* were used */
 
 /* Variables from controlling input and output scripts */
-FILE *inscr,*outscr;    /* Incoming and outgoing script file */
-int incount,outcount;   /* Current script input and */
+GOLDDIG_EXTERN FILE *inscr,*outscr;    /* Incoming and outgoing script file */
+GOLDDIG_EXTERN int incount,outcount;   /* Current script input and */
                         /* output order count */
 
-Display *disp;          /* X11 display of client */
-Window wind;            /* X11 window where game is displayed */
-int scrn;               /* Which screen is in use */
-unsigned long background; /* background color (color displays) */
-char *geom;             /* Display geometry description string */
+GOLDDIG_EXTERN Display *disp;          /* X11 display of client */
+GOLDDIG_EXTERN Window wind;            /* X11 window where game is displayed */
+GOLDDIG_EXTERN int scrn;               /* Which screen is in use */
+GOLDDIG_EXTERN unsigned long background; /* background color (color displays) */
+GOLDDIG_EXTERN char *geom;             /* Display geometry description string */
  
 /* Enumerated type to described direction or activity */
 enum directs {
   UNMOVE = 0,STAND = 1,UP = 2,DOWN = 3,LEFT = 4,RIGHT = 5,
   DIGLEFT = 6,DIGRIGHT = 7,PUTDOWN = 8
 };
-enum directs curorder;  /* Current order which player has */
+GOLDDIG_EXTERN enum directs curorder;  /* Current order which player has */
                         /* typed at the keyboard. */
-enum directs inorder,outorder;  /* Current script input and */
+GOLDDIG_EXTERN enum directs inorder,outorder;  /* Current script input and */
                                 /* output order */
 /* Structure describing all stats of thing */
-struct thing_s {
+GOLDDIG_EXTERN struct thing_s {
   int xstart,ystart;        /* Starting position of thing.  For both */
                             /* this pair and (xpos,ypos), the value is */
                             /* actually 2 times the expected value. */
@@ -111,9 +115,9 @@ struct thing_s {
 #define BADGUY 'b'
  
 #define MAXLEVEL 5000     /* Maximum size of a level */
-unsigned char level[MAXLEVEL];     /* Array describing level using */
+GOLDDIG_EXTERN unsigned char level[MAXLEVEL];     /* Array describing level using */
 				   /* characters  from above */
-unsigned char moveallow[MAXLEVEL]; /* Array describing which directions can */
+GOLDDIG_EXTERN unsigned char moveallow[MAXLEVEL]; /* Array describing which directions can */
 				   /* be moved out of any position in level */
 /* Bit patterns for moveallow array */
 #define MOVEUP    0x1   /* Upward movement is allowed */
@@ -146,7 +150,7 @@ struct symbs_s {
  
 /* Array for fast lookup of block types.  This array is index by the */
 /* actual block character. */
-struct fast_s {
+GOLDDIG_EXTERN struct fast_s {
   GC gc;        /* Graphics cursor used for drawing block */
   long code;    /* Code describing block properties */
 } fast_lookup[256];
