--- src/gfx/drivers/directfb_driver.c.orig	Thu Feb 20 17:37:19 2003
+++ src/gfx/drivers/directfb_driver.c	Thu Feb 20 17:37:46 2003
@@ -611,7 +611,7 @@
 
 	switch (pixel_format) {
 
-	case DSPF_RGB15:
+	case DSPF_ARGB1555:
 		*bytespp = 2;
 		*rm = 5; _rs = 10;
 		*gm = 5; _gs = 5;
