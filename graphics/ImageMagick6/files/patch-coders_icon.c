From e08e321e2a763325329e5c4748ef374ec9e3b76a Mon Sep 17 00:00:00 2001
From: Cristy <urban-warrior@imagemagick.org>
Date: Sun, 18 Nov 2018 17:40:50 -0500
Subject: [PATCH] https://github.com/ImageMagick/ImageMagick/issues/1386

---
 coders/icon.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/coders/icon.c b/coders/icon.c
index 5f4657f6f..c9b748d77 100644
--- coders/icon.c
+++ coders/icon.c
@@ -372,8 +372,8 @@ static Image *ReadICONImage(const ImageInfo *image_info,
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
