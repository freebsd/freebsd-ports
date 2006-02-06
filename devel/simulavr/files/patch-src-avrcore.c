--- src/avrcore.c.orig	Thu Jan 13 21:27:59 2005
+++ src/avrcore.c	Mon Feb  6 17:47:11 2006
@@ -394,6 +394,7 @@
                                     words here */
 
     core->flash = flash_new (flash_sz);
+    core->eeprom = 0;
 
     core->breakpoints = NULL;
 
