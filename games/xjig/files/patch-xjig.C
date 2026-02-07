--- xjig.C.orig	Wed Jul 24 13:14:28 1996
+++ xjig.C	Tue Apr  7 15:34:34 1998
@@ -61,7 +61,8 @@
 Window	win;
 GC			gc;
 
-int texture_mode=0;				// mode for texture mapping depending on depth
+int pixmap_depth = 0;
+int scanline_pad = 0;
 
 Cursor	normal_cursor, move_cursor, pull_cursor, idle_cursor, no_cursor;
 
@@ -324,7 +325,7 @@
 	printf( "         -sa        : shuffle angles\n" );
 	printf( "         -sp        : shuffle positions\n" );
 	printf( "         -r         : rotation demo\n" );
-	printf( "         -8 -16 -32 : manually select optimized texture mapping routine\n" );
+	printf( "         -8 -16 -24 -32 : manually select optimized texture mapping routine\n" );
 	printf( "         -dist <n>  : distortion percentage\n" );
 	printf( "         -maxang <n>: maximum rotation angle at startup\n" );
 	printf( "         -rand <n>  : seed for random generator\n" );
@@ -392,9 +393,10 @@
 #ifdef PINUP_DEFAULT
 		else if (!strcmp(argv[i],"-pinup"))			filename=PINUP_DEFAULT;
 #endif
-		else if (!strcmp(argv[i],"-8"))				texture_mode=1;
-		else if (!strcmp(argv[i],"-16"))				texture_mode=2;
-		else if (!strcmp(argv[i],"-32"))				texture_mode=3;
+		else if (!strcmp(argv[i],"-8"))				pixmap_depth=8;
+		else if (!strcmp(argv[i],"-16"))				pixmap_depth=16;
+		else if (!strcmp(argv[i],"-32"))				pixmap_depth=32;
+		else if (!strcmp(argv[i],"-24"))				pixmap_depth=24;
 		else if (!strcmp(argv[i],"-shm"))			shared=1;
 		else if (!strcmp(argv[i],"-no_shm"))		shared=0;
 		else if (!strcmp(argv[i],"-shapes"))		shapes=1;
@@ -465,30 +467,34 @@
 	printf( "xjig V2.4, by Helmut Hoenig, July-24-96\n" );
 	printf( "\n" );
 
-	if (!texture_mode) {
-		//
-		// check screen depth to select function for texture mappings
-		//
-		switch(DefaultDepth(dpy,scr)) {
-		case 8:		texture_mode=1;	break;
-		case 16:		texture_mode=2;	break;
-		case 24:
-		case 32:		texture_mode=3;	break;
+	XPixmapFormatValues *pmf;
+
+	int n;
+	pmf = XListPixmapFormats (dpy, &n);
+	if (pmf) {
+		for (int i = 0; i < n; i++) {
+			if (pixmap_depth) {
+				if (pixmap_depth == pmf[i].depth) {
+					scanline_pad = pmf[i].scanline_pad;
+					break;
+				}
+			} else if (pmf[i].depth == DefaultDepth(dpy,scr)) {
+				pixmap_depth = pmf[i].depth;
+				scanline_pad = pmf[i].scanline_pad;
+				break;
+			}
 		}
+		XFree ((char *) pmf);
 	}
-	if (!texture_mode) {
-		fprintf( stderr, "*** Unable to select texture mode for Depth %d\n", DefaultDepth(dpy,scr) );
-		fprintf( stderr, "    You can manually select one by trying either -8, -16 or -32\n" );
-		fprintf( stderr, "    Good Luck.\n" );
-		exit(0);
+
+
+	if (!scanline_pad) {
+		fprintf(stderr,"No matching depth mode found\n");
+		exit(1);
 	}
 
 	if (verbose) {
-		switch( texture_mode ) {
-		case 1: printf( "texture mode 1: 1 byte\n" ); break;
-		case 2: printf( "texture mode 2: 2 byte\n" ); break;
-		case 3: printf( "texture mode 3: 4 byte\n" ); break;
-		}
+		printf("depth: %d  pad: %d\n",pixmap_depth,scanline_pad);
 	}
 
 	old_handler=XSetErrorHandler( error_handler );
