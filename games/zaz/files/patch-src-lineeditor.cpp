--- src/lineeditor.cpp.orig	2009-09-27 04:09:24.000000000 +0400
+++ src/lineeditor.cpp	2009-10-10 03:52:38.000000000 +0400
@@ -39,7 +39,8 @@
 {
     SDL_EnableUNICODE(SDL_DISABLE);
 #ifndef WIN32
-    iconv_close(convdesc);
+	if (convdesc != (iconv_t)(-1))
+		iconv_close(convdesc);
 #endif
 }
 
@@ -161,7 +162,7 @@
                 Uint16 uni = *i;
                 size_t in_left = 2;
                 size_t out_left = 2;
-                char *in_ptr = (char *)&uni;
+                const char *in_ptr = (char *)&uni;
                 char uc[3];
                 char *out_ptr = uc;
 
