--- xworld.c.orig	1999-07-28 15:39:11 UTC
+++ xworld.c
@@ -63,6 +63,8 @@
 #define BORDER       5
 #define SLEEP      120
 
+#define MIN(x,y)   (((x)<(y))?(x):(y)) 
+
 char *MainTitle[] = {"Hello, world"};
 char *IconTitle[] = {"xworld"};
 
@@ -92,6 +94,26 @@ usage()
     exit(1);
 }
 
+
+static char *
+alloc_image(XImage *image)
+{
+    char *Map;
+    int ix, iy, j;
+    Map = (char *)malloc(image->height * image->bytes_per_line);
+    if (Map == NULL) {
+	fprintf(stderr, "xworld: not enough memory\n");
+	exit(1);
+    }
+    image->data = Map; 
+    
+    for(j = 0, ix = 0; ix < image->width; ix++)
+	for (iy = 0; iy < image->height; iy++)
+	    XPutPixel(image, ix, iy, j++ % NCOLORS);
+    
+    return Map;
+}
+
 int
 main(int argc, char **argv)
 {
@@ -305,29 +327,16 @@ main(int argc, char **argv)
         xcolor[i].blue = color[i].blue;
         if (XAllocColor(display, cmap, &xcolor[i]) == 0) {
             fprintf(stderr, "xworld: can't allocate colors\n");
+#if 0
             exit(-1);
+#endif
         }
     } 
 
 /*
  * generate startup image
  */
-    Map = (char *)malloc(size*size*sizeof(char));
-    if (Map == NULL) {
-        fprintf(stderr, "xworld: not enough memory\n");
-        exit(1);
-    }
-  
-    j = 0;
-    for (iy = 0; iy < size; iy++) {
-        i = iy % (NCOLORS + 1);
-        for (ix = 0; ix < size; ix++) {
-            *(Map + j++) = xcolor[i].pixel;
-            if (i++ >= NCOLORS) i = 0;
-        }
-    }
-   
-    image->data = Map; 
+    Map = alloc_image(image);
 
     gc = XCreateGC(display, win, 0, 0);
 
@@ -414,21 +423,21 @@ main(int argc, char **argv)
  * Map elevations to colors
  */
                     if (i != SOK) {
-                        *(Map + j) = xcolor[BLACK].pixel;
+			XPutPixel(image, ix, iy, xcolor[BLACK].pixel);
                         continue;
                     }
                     if (Value > level[NLEVELS - 1]) {
-                        *(Map + j) = xcolor[HIGH].pixel;
+			XPutPixel(image, ix, iy, xcolor[HIGH].pixel);
                         continue;
                     }
                     for (i = 0; i <= NLEVELS - 1; i++) {
                         if (Value <= level[i]) {
-                            *(Map + j) = xcolor[i].pixel;
+			    XPutPixel(image, ix, iy, xcolor[i].pixel);
                             break;
                         }
                     }
                 } else
-                    *(Map + j) = xcolor[BLACK].pixel;
+		    XPutPixel(image, ix, iy, xcolor[BLACK].pixel);
             }
         }
         XPutImage(display, win, gc, image, 0, 0, 0, 0, size, size);
@@ -444,8 +453,12 @@ main(int argc, char **argv)
                     ConfigureEvent = (XConfigureEvent *)&event;
                     size = ConfigureEvent->width;
                     if (ConfigureEvent->height != size) {
+#if 0
                         fprintf(stderr, "xworld: error: width != height\n");
                         exit(1);
+#else
+			size = MIN(size, ConfigureEvent->height);
+#endif
                     }
                     if (size != old_size) {
                         old_size = size;
@@ -453,28 +466,14 @@ main(int argc, char **argv)
                         r1 = n/2;
                         r2 = size/2;
                         XDestroyImage(image);
-                        free(Map);
                         image = XCreateImage(display, visual, depth, format,
                           0, 0, size, size, bitmap_pad, 0);
                         if (image == NULL) {
                             fprintf(stderr, "xworld: can't create XImage\n");
                             exit(1);
                         }
-                        Map = (char *)malloc(size*size*sizeof(char));
-                        if (Map == NULL) {
-                            fprintf(stderr, "xworld: not enough memory\n");
-                            exit(1);
-                        }
-                        image->data = Map; 
+			Map = alloc_image(image);
  
-                        j = 0;
-                        for (iy = 0; iy < size; iy++) {
-                            i = iy % (NCOLORS + 1);
-                            for (ix = 0; ix < size; ix++) {
-                                *(Map + j++) = xcolor[i].pixel;
-                                if (i++ >= NCOLORS) i = 0;
-                            }
-                        }
                         XPutImage(display, win, gc, image, 0, 0, 0, 0,
                           size, size);
                         break;
