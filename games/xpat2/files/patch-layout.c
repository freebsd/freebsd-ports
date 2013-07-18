--- layout.c.orig
+++ layout.c
@@ -332,17 +332,9 @@
 	}
     } else {
 	/* enough space for the slots! */
-	int currentx = geo.dx;
-/*	printf("generating high layout for %d,%d\n", geo.w, geo.h); */
-	if (rem_x >= (rules.numslots + 1) * (geo.cw + geo.dx) &&
-	    !(rules.variant & NODEAL)) {
-	    /* there is space for the deck, and we can use one! */
-	    geo.pg[game.numpiles-1].x = geo.dx;
-	    geo.pg[game.numpiles-1].y = geo.dy + geo.ch + geo.dy;
-	    currentx += geo.cw + geo.dx;
-	    new_layout_type = GEN_BIG_LAYOUT_WITH_DECK;
-	    geo.preferred_width += geo.dx + geo.cw;
-	}
+	int currentx = geo.dx + rules.numdecks * (geo.cw + geo.dx);
+	new_layout_type = GEN_BIG_LAYOUT_WITH_DECK;
+	geo.preferred_width += rules.numdecks * (geo.dx + geo.cw);
 	for (i = 0; i < rules.numslots; ++i) {
 	    /* create slot of full window height */
 	    p->x = currentx;
@@ -351,6 +343,14 @@
 	    currentx += geo.cw + geo.dx;
 	    ++p;
 	}
+	/* finally, position the decks */
+	for (i = 0; i < rules.numdecks; ++i) {
+	    p[0].x = i * (geo.dx + geo.cw);
+	    p[1].x = p[0].x;
+	    p[0].y = geo.dy + 2 * (geo.ch + geo.dy);
+	    p[1].y = geo.dy + geo.ch + geo.dy;
+	    p += 2;
+	}
 	/* redo pos. of stacks */
 	p = geo.pg;
 	for (i = 0; i < rules.numstacks; ++i) {
