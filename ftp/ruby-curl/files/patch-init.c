--- init.c.orig	Thu May 16 02:07:22 2002
+++ init.c	Fri May 24 18:12:22 2002
@@ -380,10 +380,10 @@
 #include "auto_defs.inc"
 /***************************************************************/
 
-   rb_define_const(cCurl, "TIMECOND_NONE", INT2FIX(TIMECOND_NONE));
-   rb_define_const(cCurl, "TIMECOND_IFMODSINCE", INT2FIX(TIMECOND_IFMODSINCE));
-   rb_define_const(cCurl, "TIMECOND_IFUNMODSINCE", INT2FIX(TIMECOND_IFUNMODSINCE));
-   rb_define_const(cCurl, "TIMECOND_LASTMOD", INT2FIX(TIMECOND_LASTMOD));
+   rb_define_const(cCurl, "TIMECOND_NONE", INT2FIX(CURL_TIMECOND_NONE));
+   rb_define_const(cCurl, "TIMECOND_IFMODSINCE", INT2FIX(CURL_TIMECOND_IFMODSINCE));
+   rb_define_const(cCurl, "TIMECOND_IFUNMODSINCE", INT2FIX(CURL_TIMECOND_IFUNMODSINCE));
+   rb_define_const(cCurl, "TIMECOND_LASTMOD", INT2FIX(CURL_TIMECOND_LASTMOD));
 
    rb_define_const(cCurl, "HTTP_VERSION_NONE", INT2FIX(CURL_HTTP_VERSION_NONE));
    rb_define_const(cCurl, "HTTP_VERSION_1_0", INT2FIX(CURL_HTTP_VERSION_1_0));
