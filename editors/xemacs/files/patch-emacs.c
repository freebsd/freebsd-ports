--- src/emacs.c.orig	Wed Jan 15 07:18:00 2003
+++ src/emacs.c	Tue Jul 20 12:02:41 2004
@@ -344,7 +344,7 @@
 #endif
 
 /* Number of bytes of writable memory we can expect to be able to get */
-unsigned int lim_data;
+rlim_t lim_data;
 
 /* WARNING!
 
