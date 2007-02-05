--- utils/converters/autocad/message.c.orig	Fri May  9 23:58:55 2003
+++ utils/converters/autocad/message.c	Mon Feb  5 21:47:50 2007
@@ -3,7 +3,7 @@
 #include <signal.h>
 #include <stdarg.h>
 
-void Msg(int level, char *fmt, ...)
+void Msg(int level, const char *fmt, ...)
 {
   va_list args;
   va_start(args, fmt);
