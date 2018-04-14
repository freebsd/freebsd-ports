--- src/log/iwlog.c.orig	2018-04-12 13:48:26 UTC
+++ src/log/iwlog.c
@@ -383,16 +383,9 @@ static iwrc _default_logfn(locale_t locale,
     ecode_msg = _ecode_explained(locale, ecode);
   }
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
-  char bfile[MAXPATHLEN];
   if (file && line > 0) {
-    file = basename_r(file, bfile);
-  }
-#else
-  if (file && line > 0) {
     file = basename(file);
   }
-#endif
 
   if (ecode || errno_code || werror_code) {
     if (file && line > 0) {
