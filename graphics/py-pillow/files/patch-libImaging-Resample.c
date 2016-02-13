From 41fae6d9e2da741d2c5464775c7f1a609ea03798 Mon Sep 17 00:00:00 2001
From: Ned Williamson <nedwilliamson@gmail.com>
Date: Thu, 4 Feb 2016 01:54:12 -0500
Subject: [PATCH] fix integer overflow in Resample.c

---
 libImaging/Resample.c | 12 ++++++++++++
 1 file changed, 12 insertions(+)

--- libImaging/Resample.c
+++ libImaging/Resample.c
@@ -138,11 +138,23 @@ ImagingResampleHorizontal(Imaging imIn, int xsize, int filter)
     /* maximum number of coofs */
     kmax = (int) ceil(support) * 2 + 1;
 
+    // check for overflow
+    if (kmax > 0 && xsize > SIZE_MAX / kmax)
+        return (Imaging) ImagingError_MemoryError();
+
+    // sizeof(float) should be greater than 0
+    if (xsize * kmax > SIZE_MAX / sizeof(float))
+        return (Imaging) ImagingError_MemoryError();
+
     /* coefficient buffer */
     kk = malloc(xsize * kmax * sizeof(float));
     if ( ! kk)
         return (Imaging) ImagingError_MemoryError();
 
+    // sizeof(int) should be greater than 0 as well
+    if (xsize > SIZE_MAX / (2 * sizeof(int)))
+        return (Imaging) ImagingError_MemoryError();
+
     xbounds = malloc(xsize * 2 * sizeof(int));
     if ( ! xbounds) {
         free(kk);
