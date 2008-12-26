--- uftp.h.orig	2008-12-26 16:59:05.000000000 +0300
+++ uftp.h	2008-12-26 16:59:14.000000000 +0300
@@ -338,7 +338,7 @@ void info_ntoh(struct fileinfo *info)
   info->lolargefsize=ntohl(info->lolargefsize);
 }
 
-void logfunc(FILE *logf, int32_t id, int newline, int err, int sockerr, char str[], ...)
+void logfunc(FILE *logf, uint32_t id, int newline, int err, int sockerr, char str[], ...)
 {
   va_list args;
  
