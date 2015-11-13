--- sope-core/NGExtensions/FdExt.subproj/NSString+Encoding.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/FdExt.subproj/NSString+Encoding.m
@@ -209,7 +209,7 @@ static char *iconv_wrapper(id self, char
   tm           = outbuf;
   outbytesleft = outlen;
 
-  write = iconv(type, &inbuf, &inbytesleft, &tm, &outbytesleft);
+  write = iconv(type, (void*)&inbuf, &inbytesleft, &tm, &outbytesleft);
 
   if (write == (size_t)-1) {
     if (errno == EILSEQ) {
