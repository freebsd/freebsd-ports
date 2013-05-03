--- icc_gl.cpp.orig	2013-05-01 21:38:55.000000000 +0400
+++ icc_gl.cpp	2013-05-01 21:39:28.000000000 +0400
@@ -191,7 +191,7 @@ void drawText( FTFont * f, const char * 
     ttmp = txt = strdup(in_txt);
 
     iconv_t cd = iconv_open( "WCHAR_T", oy_domain_codeset );
-    iconv( cd, &ttmp, &in_left, (char**)&wtmp, &out_left);
+    iconv( cd, (const char**)&ttmp, &in_left, (char**)&wtmp, &out_left);
     iconv_close( cd );
 
     drawTEXT( f, wchar );
