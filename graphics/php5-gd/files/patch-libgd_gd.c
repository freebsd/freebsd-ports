--- libgd/gd.c.orig	2009-01-05 14:54:19.000000000 +0100
+++ libgd/gd.c	2009-01-05 14:54:53.000000000 +0100
@@ -3136,7 +3136,7 @@
 		return NULL;
 	}
 
-	if (!gdImageTrueColor(src) && clrBack>=gdImageColorsTotal(src)) {
+	if (!gdImageTrueColor(src) && (clrBack < 0 || clrBack>=gdImageColorsTotal(src))) {
 		return NULL;
 	}
 
