See:

	https://bugs.php.net/bug.php?id=75571

--- src/gd_gif_in.c	2017-08-30 07:05:54.000000000 -0400
+++ src/gd_gif_in.c	2018-07-11 15:39:11.746181000 -0400
@@ -336,9 +336,4 @@
 	}
 
-	if(!im->colorsTotal) {
-		gdImageDestroy(im);
-		return 0;
-	}
-
 	/* Check for open colors at the end, so
 	 * we can reduce colorsTotal and ultimately
@@ -352,4 +347,9 @@
 	}
 
+	if(!im->colorsTotal) {
+		gdImageDestroy(im);
+		return 0;
+	}
+
 	return im;
 }
@@ -447,6 +447,5 @@
 GetCode_(gdIOCtx *fd, CODE_STATIC_DATA *scd, int code_size, int flag, int *ZeroDataBlockP)
 {
-	int i, j, ret;
-	unsigned char count;
+	int i, j, ret, count;
 
 	if(flag) {
