--- src/emacs.c.orig	Sun Mar  9 03:37:54 2003
+++ src/emacs.c	Tue Jul 20 21:59:42 2004
@@ -398,7 +398,7 @@
 
 /* Number of bytes of writable memory we can expect to be able to get:
    Leave this as an unsigned int because it could potentially be 4G */
-unsigned int lim_data;
+rlim_t lim_data;
 
 /* WARNING!
 
