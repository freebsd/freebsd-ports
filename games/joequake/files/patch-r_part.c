--- ./r_part.c.orig	Sat Apr  1 11:31:48 2006
+++ ./r_part.c	Sat May 20 10:00:24 2006
@@ -59,7 +59,7 @@
 
 vec3_t			r_pright, r_pup, r_ppn;
 
-#if !id386
+#if !id386 && !defined(GLQUAKE)
 
 /*
 ==============
