--- src/p_link.c.orig	Sat Dec 18 15:05:44 2004
+++ src/p_link.c	Sat Dec 18 15:06:05 2004
@@ -554,7 +554,7 @@
     }
 #endif
     pcontext;
-br:
+br:;
 }
 
 /* error handler for the link checking */
