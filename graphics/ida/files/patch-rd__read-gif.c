--- rd/read-gif.c.orig	2012-02-23 02:13:36.000000000 +0900
+++ rd/read-gif.c	2012-09-10 18:52:32.000000000 +0900
@@ -13,6 +13,17 @@
     int w,h;
 };
 
+static void
+localPrintGifError(void)
+{
+    char *Err = GifErrorString();
+
+    if (Err != NULL)
+	fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+	fprintf(stderr, "\nGIF-LIB undefined error %d.\n", GifError());
+}
+
 static GifRecordType
 gif_fileread(struct gif_state *h)
 {
@@ -25,7 +36,7 @@
 	if (GIF_ERROR == DGifGetRecordType(h->gif,&RecordType)) {
 	    if (debug)
 		fprintf(stderr,"gif: DGifGetRecordType failed\n");
-	    PrintGifError();
+	    localPrintGifError();
 	    return -1;
 	}
 	switch (RecordType) {
@@ -42,7 +53,7 @@
 		if (rc == GIF_ERROR) {
 		    if (debug)
 			fprintf(stderr,"gif: DGifGetExtension failed\n");
-		    PrintGifError();
+		    localPrintGifError();
 		    return -1;
 		}
 		if (debug) {
@@ -108,7 +119,7 @@
 	    if (GIF_ERROR == DGifGetImageDesc(h->gif)) {
 		if (debug)
 		    fprintf(stderr,"gif: DGifGetImageDesc failed\n");
-		PrintGifError();
+		localPrintGifError();
 	    }
 	    if (NULL == h->gif->SColorMap &&
 		NULL == h->gif->Image.ColorMap) {
