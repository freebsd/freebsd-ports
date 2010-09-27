--- ../../src/wrapper.c.orig	2010-08-22 16:53:22.000000000 -0400
+++ ../../src/wrapper.c	2010-09-20 11:55:46.000000000 -0400
@@ -40,7 +40,7 @@
     }
     /* we log all logLevel < LOGLEVEL*/
     else if (LOGLEVEL >= 0 &&
-             logLevel >= LOGLEVEL)
+             logLevel > LOGLEVEL)
     {
         return;
     }
