--- r_part.c.orig	Fri Aug 26 15:02:44 2005
+++ r_part.c	Sun Jan 15 02:00:02 2006
@@ -59,7 +59,7 @@
 
 vec3_t			r_pright, r_pup, r_ppn;
 
-#if !id386
+#if !id386 && !defined(GLQUAKE)
 
 /*
 ==============
