--- src/ImageData.cpp.orig	2007-12-12 22:07:21.000000000 +0100
+++ src/ImageData.cpp	2010-03-29 09:29:18.000000000 +0200
@@ -395,7 +395,7 @@
   /* Check for the 8-byte signature */
   fread(sig, 1, 8, infile);
 
-  if (!png_check_sig((unsigned char *) sig, 8))
+  if (png_sig_cmp((unsigned char *) sig, 0, 8))
   {
     fclose(infile);
     return false; // seems not to be a valid png file
