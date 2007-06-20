--- drawcard.c.orig	Thu Apr  2 05:55:06 1992
+++ drawcard.c	Fri Jun 15 02:09:15 2007
@@ -8,6 +8,8 @@
 # include	"ui.h"
 # include	"card.h"
 # include	"background.h"
+# include	<stdlib.h>
+
 
 struct card_init {
 	char	*bits;
@@ -64,6 +66,9 @@
 struct card backside;
 struct card eraseCard;
 
+static drawIm();
+static redisplaybelow();
+
 
 bw_init_cards()
 {
@@ -183,12 +188,12 @@
 				WIDTH, HEIGHT);
 		
 		XSetForeground(dpy, cheap_gc, bits_p);
-		XSetStipple(dpy, cheap_gc, bits);
+		XSetStipple(dpy, cheap_gc, mask);
 		XFillRectangle (dpy, cards[i].bits, cheap_gc, 0, 0,
 				WIDTH, HEIGHT);
 		
 		XSetForeground(dpy, cheap_gc, mask_p);
-		XSetStipple(dpy, cheap_gc, mask);
+		XSetStipple(dpy, cheap_gc, bits);
 		XFillRectangle (dpy, cards[i].bits, cheap_gc, 0, 0,
 				WIDTH, HEIGHT);
 		
@@ -262,7 +267,6 @@
 struct card	*c;
 {
 	struct displayed	*d, *p;
-	char			*malloc ();
 
 	p = 0;
 	for (d = onscreen; d; d = d->next) {
