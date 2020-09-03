--- globals.h.orig	1991-09-28 17:46:20 UTC
+++ globals.h
@@ -10,40 +10,47 @@
  *
  */
 
+#ifdef IN_MAIN
+#define EXTERN
+#warning EXTERN
+#else
+#define EXTERN extern
+#endif
+
 /*
  * spider global variables
  */
-Display	*dpy;
-int	screen;
-Window	table;
+EXTERN Display	*dpy;
+EXTERN int	screen;
+EXTERN Window	table;
 #ifdef 	KITLESS
 Window	message_win;
 XFontStruct	*message_font;
 #endif	/* KITLESS */
-Pixmap	greenmap;
-Pixmap	redmap;
-Pixmap	logomap;
+EXTERN Pixmap	greenmap;
+EXTERN Pixmap	redmap;
+EXTERN Pixmap	logomap;
 
-unsigned long	blackpixel;
-unsigned long	whitepixel;
-unsigned long	borderpixel;
-unsigned long	greenpixel;
+EXTERN unsigned long	blackpixel;
+EXTERN unsigned long	whitepixel;
+EXTERN unsigned long	borderpixel;
+EXTERN unsigned long	greenpixel;
 
-Bool	is_color;
+EXTERN Bool	is_color;
 
-CardList	deck;
-CardList	stack[NUM_STACKS];		/* tableau */
-CardList	piles[NUM_PILES];		/* full suits */
+EXTERN CardList	deck;
+EXTERN CardList	stack[NUM_STACKS];		/* tableau */
+EXTERN CardList	piles[NUM_PILES];		/* full suits */
 
-int		table_height;
-int		table_width;
+EXTERN int	table_height;
+EXTERN int	table_width;
 
-int		deck_index;
+extern int	deck_index;
 
-int		draw_count;
+EXTERN int	draw_count;
 
-Bool		restart;
-int		deal_number;
+EXTERN Bool	restart;
+EXTERN int	deal_number;
 
 extern char	*version;
 extern char	*build_date;
@@ -96,6 +103,10 @@ void	do_expand();
 Bool	can_get_help_files();
 #endif
 
-extern char	*malloc();
-extern char	*calloc();
-extern char	*realloc();
+#ifndef __FreeBSD__
+EXTERN char	*malloc();
+EXTERN char	*calloc();
+EXTERN char	*realloc();
+#else
+#include <stdlib.h>
+#endif
