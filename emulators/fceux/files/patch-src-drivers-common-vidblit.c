--- src/drivers/common/vidblit.c.orig	Tue Dec 21 15:43:20 2004
+++ src/drivers/common/vidblit.c	Tue Dec 21 15:43:44 2004
@@ -79,7 +79,7 @@
 {
  if(specfilt == 2 || specfilt == 4) // scale2x and scale3x
  {
-  int multi;
+  int multi = 0;
 
   if(specfilt == 2) multi = 2 * 2;
   else if(specfilt == 4) multi = 3 * 3;
