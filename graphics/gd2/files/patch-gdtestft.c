--- gdtestft.c.orig	Thu Apr 25 14:17:03 2002
+++ gdtestft.c	Wed Nov  7 00:43:02 2001
@@ -18,6 +18,8 @@
 #define MAXY(x) MAX4(x[1],x[3],x[5],x[7])
 #define MINY(x) MIN4(x[1],x[3],x[5],x[7])
 
+void CompareImages(char *msg, gdImagePtr im1, gdImagePtr im2);
+
 int
 main (int argc, char *argv[])
 {
@@ -28,13 +30,13 @@
   fprintf (stderr, "make clean, and type make again.\n");
   return 1;
 #else
-  gdImagePtr im;
+  gdImagePtr im, ref;
   int black;
   int white;
   int brect[8];
   int x, y;
   char *err;
-  FILE *out;
+  FILE *out, *in;
 #ifdef JISX0208
   char *s = "Hello. ‚±‚ñ‚É‚¿‚Í Qyjpqg,";	/* String to draw. */
 #else
@@ -67,8 +69,8 @@
   /* create an image just big enough for the string */
   x = MAXX (brect) - MINX (brect) + 6;
   y = MAXY (brect) - MINY (brect) + 6;
-#if 0
-  im = gdImageCreate (500, 500);
+#if 0 
+  im = gdImageCreate (x, y);
 #else
   /* gd 2.0: true color images can use freetype too */
   im = gdImageCreateTrueColor (x, y);
@@ -90,6 +92,16 @@
       fprintf (stderr, err);
       return 1;
     }
+
+  in = fopen("test/fttestref.png", "rb");
+  if (!in) {
+      fprintf(stderr, "Input file does not exist!\n");
+      exit(1);
+  }
+  ref = gdImageCreateFromPng(in);
+
+  fclose(in);
+
   /* TBB: Write img to test/fttest.png */
   out = fopen ("test/fttest.png", "wb");
   if (!out)
@@ -100,9 +112,43 @@
   gdImagePng (im, out);
   fclose (out);
   fprintf (stderr, "Test image written to test/fttest.png\n");
+
+  CompareImages("FTTest Image", ref, im);
+
   /* Destroy it */
   gdImageDestroy (im);
+  gdImageDestroy(ref);
 
   return 0;
 #endif /* HAVE_FREETYPE */
 }
+
+void CompareImages(char *msg, gdImagePtr im1, gdImagePtr im2)
+{
+	int cmpRes;
+
+	cmpRes = gdImageCompare(im1, im2);
+
+	if (cmpRes & GD_CMP_IMAGE) {
+		printf("%%%s: ERROR images differ: BAD\n",msg);
+	} else if (cmpRes != 0) {
+		printf("%%%s: WARNING images differ: WARNING - Probably OK\n",msg);
+	} else {
+		printf("%%%s: OK\n",msg);
+		return;
+	}
+
+	if (cmpRes & (GD_CMP_SIZE_X + GD_CMP_SIZE_Y)) {
+		printf("-%s: INFO image sizes differ\n",msg);
+	}
+
+	if (cmpRes & GD_CMP_NUM_COLORS) {
+		printf("-%s: INFO number of pallette entries differ %d Vs. %d\n",msg,
+			im1->colorsTotal, im2->colorsTotal);
+	}
+
+	if (cmpRes & GD_CMP_COLOR) {
+		printf("-%s: INFO actual colours of pixels differ\n",msg);
+	}
+}
+
