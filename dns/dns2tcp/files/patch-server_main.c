--- server/main.c.orig	2020-08-28 19:28:55 UTC
+++ server/main.c
@@ -42,6 +42,8 @@
 #include "myerror.h"
 #include "log.h"
 
+int debug;
+
 int			detach_process(t_conf *conf)
 {
   int			fd;
