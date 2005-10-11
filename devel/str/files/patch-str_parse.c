--- str_parse.c.orig	Mon Jan 24 13:20:22 2005
+++ str_parse.c	Tue Oct 11 13:44:59 2005
@@ -297,6 +297,7 @@
     char buf2[128];
     char *buf_ptr;
     str_vformat_t sf;
+    va_list ap_temp;
 
     /*
      * Caching support
@@ -564,7 +565,9 @@
         sf.data[3].p = (char *)string;
         sf.data[4].p = cap_vec;
         sf.data[5].i = cap_num;
-        l = str_vformat(&sf, buf_ptr, ap);
+        /* we shall need `ap' untouched later */
+        va_copy(ap_temp, ap);
+        l = str_vformat(&sf, buf_ptr, ap_temp);
 
         /* allocate output buffer */
         if ((*cpp = (char *)malloc(l+1)) == NULL) {
