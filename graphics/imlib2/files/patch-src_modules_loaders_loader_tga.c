--- src/modules/loaders/loader_tga.c.orig	Wed Nov  8 19:48:53 2006
+++ src/modules/loaders/loader_tga.c	Wed Nov  8 19:54:47 2006
@@ -319,6 +319,7 @@
      {
         unsigned long       datasize;
         unsigned char      *bufptr;
+        unsigned char      *bufend;
         DATA32             *dataptr;
 
         int                 y;
@@ -347,6 +348,9 @@
         /* bufptr is the next byte to be read from the buffer */
         bufptr = filedata;
 
+        /* bufend is one past the last byte to be read from the buffer */
+        bufend = filedata + datasize;
+
         /* dataptr is the next 32-bit pixel to be filled in */
         dataptr = im->data;
 
@@ -364,7 +368,8 @@
                   else
                      dataptr = im->data + (y * im->w);
 
-                  for (x = 0; x < im->w; x++)   /* for each pixel in the row */
+		  /* for each pixel in the row */
+                  for (x = 0; x < im->w && ((bufptr + bpp/8) < bufend); x++)
                     {
                        switch (bpp)
                          {
@@ -419,7 +424,7 @@
              DATA32             *final_pixel = dataptr + im->w * im->h;
 
              /* loop until we've got all the pixels */
-             while (dataptr < final_pixel)
+             while (dataptr < final_pixel && ((bufptr + 1 + bpp/8) < bufend))
                {
                   int                 count;
 
@@ -437,7 +442,7 @@
                               green = *bufptr++;
                               red = *bufptr++;
                               alpha = *bufptr++;
-                              for (i = 0; i < count; i++)
+                              for (i = 0; i < count && dataptr < final_pixel; i++)
                                 {
                                    WRITE_RGBA(dataptr, red, green, blue, alpha);
                                    dataptr++;
@@ -448,7 +453,7 @@
                               blue = *bufptr++;
                               green = *bufptr++;
                               red = *bufptr++;
-                              for (i = 0; i < count; i++)
+                              for (i = 0; i < count && dataptr < final_pixel; i++)
                                 {
                                    WRITE_RGBA(dataptr, red, green, blue,
                                               (char)0xff);
@@ -458,7 +463,7 @@
 
                            case 8:
                               alpha = *bufptr++;
-                              for (i = 0; i < count; i++)
+                              for (i = 0; i < count && dataptr < final_pixel; i++)
                                 {
                                    WRITE_RGBA(dataptr, alpha, alpha, alpha,
                                               (char)0xff);
@@ -473,7 +478,7 @@
                     {
                        int                 i;
 
-                       for (i = 0; i < count; i++)
+                       for (i = 0; i < count && dataptr < final_pixel; i++)
                          {
                             switch (bpp)
                               {
