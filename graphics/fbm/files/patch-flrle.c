--- flrle.c.orig	Mon Jun 25 04:49:20 1990
+++ flrle.c	Thu Jan 13 17:29:17 2005
@@ -31,7 +31,7 @@
 
 #ifdef RLE
 
-#include	"svfb_global.h"
+#include	"rle.h"
 
 #define		CMAP_COLORS		3
 
@@ -82,6 +82,9 @@
     int		planes;
     int		rowlen;
     int		plnlen;
+    rle_hdr	out_hdr;
+    
+    out_hdr =  *rle_hdr_init( (rle_hdr *)0 );
 
     if (image->hdr.physbits != 8) {
 	fputs ("write_rle:  error:  can only handle 8 physical bits per pixel\n",
@@ -95,19 +98,19 @@
     rowlen = image->hdr.rowlen;
     plnlen = image->hdr.plnlen;
 
-    sv_globals.sv_ncolors	= planes;
-    sv_globals.sv_alpha		= 0;  /* no alpha channel */
-    sv_globals.sv_background	= 2;  /* clear background to sv_bg_color */
-    sv_globals.sv_xmin		= 0;
-    sv_globals.sv_xmax		= cols - 1;
-    sv_globals.sv_ymin		= 0;
-    sv_globals.sv_ymax		= rows - 1;
-    sv_globals.sv_cmaplen	= 0;  /* log2(color_map_length) */
+    out_hdr.ncolors	= planes;
+    out_hdr.alpha		= 0;  /* no alpha channel */
+    out_hdr.background	= 2;  /* clear background to bg_color */
+    out_hdr.xmin		= 0;
+    out_hdr.xmax		= cols - 1;
+    out_hdr.ymin		= 0;
+    out_hdr.ymax		= rows - 1;
+    out_hdr.cmaplen	= 0;  /* log2(color_map_length) */
     if (image->hdr.clrlen > 0) {
-	sv_globals.sv_ncmap = CMAP_COLORS;
+	out_hdr.ncmap = CMAP_COLORS;
 
 	for (i = 1; i < image->hdr.clrlen / CMAP_COLORS; i <<= 1)
-	    sv_globals.sv_cmaplen++;
+	    out_hdr.cmaplen++;
 
 	if ((colorMap = (rle_map *)malloc(image->hdr.clrlen*sizeof(rle_map))) ==
 	    (rle_map *)NULL)
@@ -117,15 +120,15 @@
 	}
 	for (i = 0; i < image->hdr.clrlen; i++)
 	    colorMap[i] = (rle_map)image->cm[i] << 8;
-	sv_globals.sv_cmap	= colorMap;
+	out_hdr.cmap	= colorMap;
     }
     else {
-	sv_globals.sv_ncmap	= 0;
-	sv_globals.sv_cmap	= (rle_map *)NULL;
+	out_hdr.ncmap	= 0;
+	out_hdr.cmap	= (rle_map *)NULL;
     }
 
     for (channel = 0; channel < planes; channel++)
-	SV_SET_BIT (sv_globals, channel);
+	RLE_SET_BIT (out_hdr, channel);
 
     if (*image->hdr.title != '\0')
 	sprintf (CommentBuf (cp++), "%s=%s",
@@ -144,7 +147,7 @@
      *  in a comment.
      */
     if (image->hdr.clrlen > 0 &&
-	(1 << sv_globals.sv_cmaplen) != image->hdr.clrlen / CMAP_COLORS)
+	(1 << out_hdr.cmaplen) != image->hdr.clrlen / CMAP_COLORS)
     {
 	sprintf (CommentBuf (cp++), "%s=%d",
 			 CMAP_COMMENT, image->hdr.clrlen / CMAP_COLORS);
@@ -152,11 +155,11 @@
 
     *cp = (char *)NULL;
 
-    sv_globals.sv_comments = cp > comments ? comments : (char **)NULL;
+    out_hdr.comments = cp > comments ? comments : (char **)NULL;
 
-    sv_globals.svfb_fd		= wfile;
+    out_hdr.rle_file		= wfile;
   
-    sv_setup (RUN_DISPATCH, &sv_globals);
+    rle_put_setup (&out_hdr);
 
     if ((rowvec = (unsigned char **)malloc (planes*sizeof(unsigned char *))) ==
 	(unsigned char **)NULL)
@@ -168,9 +171,9 @@
     for (j = rows - 1; j >= 0; --j) {
 	for (channel = 0; channel < planes; channel ++)
 	    rowvec[channel] = image->bm + j * rowlen + channel * plnlen;
-	sv_putrow (rowvec, cols, &sv_globals);
+	rle_putrow (rowvec, cols, &out_hdr);
     }
-    sv_puteof (&sv_globals);
+    rle_puteof (&out_hdr);
 
     free (rowvec);
     while (cp > comments)
@@ -203,13 +206,16 @@
     int			plnlen;
     int			mapEntries;
     int			clearRow;
+    rle_hdr	in_hdr;
+    
+    in_hdr =  *rle_hdr_init( (rle_hdr *)0 );
 
     /* must put the magic number back so the setup code can read it */
     while (mlen--)
 	(void)ungetc (*mstr++, rfile);
 
-    sv_globals.svfb_fd = rfile;
-    switch (rle_get_setup (&sv_globals)) {
+    in_hdr.rle_file = rfile;
+    switch (rle_get_setup (&in_hdr)) {
 	case 0:
 	    break;	/* success */
 	case -1:
@@ -229,34 +235,34 @@
 		   stderr);
     }
 
-    if (sv_globals.sv_alpha) {
+    if (in_hdr.alpha) {
 	fputs ("read_rle:  discarding alpha channel.\n", stderr);
-	SV_CLR_BIT (sv_globals, SV_ALPHA);
+	RLE_CLR_BIT (in_hdr, RLE_ALPHA);
     }
 
-    image->hdr.cols	= sv_globals.sv_xmax - sv_globals.sv_xmin + 1;
-    image->hdr.rows	= rows = sv_globals.sv_ymax - sv_globals.sv_ymin + 1;
-    image->hdr.planes	= planes = sv_globals.sv_ncolors;
-    image->hdr.bits	= sv_globals.sv_cmaplen ? sv_globals.sv_cmaplen : 8;
+    image->hdr.cols	= in_hdr.xmax - in_hdr.xmin + 1;
+    image->hdr.rows	= rows = in_hdr.ymax - in_hdr.ymin + 1;
+    image->hdr.planes	= planes = in_hdr.ncolors;
+    image->hdr.bits	= in_hdr.cmaplen ? in_hdr.cmaplen : 8;
     image->hdr.physbits	= 8;
     image->hdr.rowlen	= rowlen = image->hdr.cols;
     image->hdr.plnlen	= plnlen = image->hdr.rows * image->hdr.rowlen;
 
-    image->hdr.clrlen	= 1 << sv_globals.sv_cmaplen;
-    if ((comment = rle_getcom (CMAP_COMMENT, &sv_globals)) != (char *)NULL)
+    image->hdr.clrlen	= 1 << in_hdr.cmaplen;
+    if ((comment = rle_getcom (CMAP_COMMENT, &in_hdr)) != (char *)NULL)
 	image->hdr.clrlen = atoi (comment);
-    image->hdr.clrlen	*= sv_globals.sv_ncmap;
+    image->hdr.clrlen	*= in_hdr.ncmap;
 
-    if ((comment = rle_getcom (ASPECT_COMMENT, &sv_globals)) != (char *)NULL)
+    if ((comment = rle_getcom (ASPECT_COMMENT, &in_hdr)) != (char *)NULL)
 	image->hdr.aspect = atof (comment);
     else
 	image->hdr.aspect = 1.0;
 
-    if ((comment = rle_getcom (TITLE_COMMENT, &sv_globals)) != (char *)NULL)
+    if ((comment = rle_getcom (TITLE_COMMENT, &in_hdr)) != (char *)NULL)
 	(void)strcpy (image->hdr.title, comment);
     else
 	image->hdr.title[0] = '\0';
-    if ((comment = rle_getcom (CREDITS_COMMENT, &sv_globals)) != (char *)NULL)
+    if ((comment = rle_getcom (CREDITS_COMMENT, &in_hdr)) != (char *)NULL)
 	(void)strcpy (image->hdr.credits, comment);
     else
 	image->hdr.credits[0] = '\0';
@@ -266,9 +272,9 @@
     alloc_fbm (image);
 
     if (image->hdr.clrlen > 0) {
-	mapEntries = (image->hdr.clrlen / sv_globals.sv_ncmap);
+	mapEntries = (image->hdr.clrlen / in_hdr.ncmap);
 	cp = image->cm;
-	colorMap = buildmap (&sv_globals, CMAP_COLORS, 1.0);
+	colorMap = buildmap (&in_hdr, CMAP_COLORS, 1.0, 1.0);
 	for (channel = 0; channel < CMAP_COLORS; channel++) {
 	    for (j = 0; j < mapEntries; j++)
 		*cp++ = colorMap[channel][j];
@@ -278,26 +284,26 @@
 	image->hdr.clrlen = mapEntries * CMAP_COLORS; /* renormalize clrlen */
     }
 
-    switch (sv_globals.sv_background) {
+    switch (in_hdr.background) {
 	case 0:		/* no background color was saved */
 	    clearRow = TRUE;	/* manually clear rows to 0 */
 	    break;
 	case 1:		/* don't clear to the background color */
-	    sv_globals.sv_background = 2;  /* force automatic clearing */
+	    in_hdr.background = 2;  /* force automatic clearing */
 	    /* fall through... */
 	case 2:		/* clear to the background color */
 	    clearRow = FALSE;
 	    break;
 	default:
 	    fprintf (stderr, "read_rle:  unknown background flag '%d'.\n",
-		     sv_globals.sv_background);
+		     in_hdr.background);
     }
 
     /* move image to origin */
-    sv_globals.sv_xmin	= 0;
-    sv_globals.sv_xmax	= image->hdr.cols - 1;
-    sv_globals.sv_ymin	= 0;
-    sv_globals.sv_ymax	= image->hdr.rows - 1;
+    in_hdr.xmin	= 0;
+    in_hdr.xmax	= image->hdr.cols - 1;
+    in_hdr.ymin	= 0;
+    in_hdr.ymax	= image->hdr.rows - 1;
 
     if ((rowvec = (unsigned char **)malloc (planes*sizeof(unsigned char *))) ==
 	(unsigned char **)NULL)
@@ -312,7 +318,7 @@
 	    if (clearRow)
 		bzero ((char *)rowvec[channel], rowlen);
 	}
-	rle_getrow (&sv_globals, rowvec);
+	rle_getrow (&in_hdr, rowvec);
     }
     free (rowvec);
 
