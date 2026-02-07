--- xmain.c.orig	2014-11-04 10:25:00 UTC
+++ xmain.c
@@ -52,6 +52,10 @@
 #include "ldef.h"
 #include "conf.h"
 
+int w3sz_offset_hz;  //w3sz offset equal to ug.par2 to be used elsewhere in program
+int w3sz_offset_hz_old;  //w3sz
+int w3sz_users_flag;//w3sz
+
 
 #if DO_NOT_USE_XKBLIB == TRUE 
 #define USE_XKBLIB 0
