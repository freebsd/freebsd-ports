From 08761138f4b3ee4d174ee4297983839c55382349 Mon Sep 17 00:00:00 2001
From: Cristy <urban-warrior@imagemagick.org>
Date: Sun, 18 Nov 2018 17:39:53 -0500
Subject: [PATCH] https://github.com/ImageMagick/ImageMagick/issues/1386

---
 coders/icon.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/coders/icon.c b/coders/icon.c
index fa35021cd5..e32c7392f8 100644
--- coders/icon.c
+++ coders/icon.c
@@ -367,8 +367,8 @@ static Image *ReadICONImage(const ImageInfo *image_info,
         png[13]=(unsigned char) (icon_info.planes >> 8);
         png[14]=(unsigned char) icon_info.bits_per_pixel;
         png[15]=(unsigned char) (icon_info.bits_per_pixel >> 8);
-        count=ReadBlob(image,length,png+16);
-        if (count != (ssize_t) length)
+        count=ReadBlob(image,length-16,png+16);
+        if (count != (ssize_t) (length-16))
           {
             png=(unsigned char *) RelinquishMagickMemory(png);
             ThrowReaderException(CorruptImageError,
