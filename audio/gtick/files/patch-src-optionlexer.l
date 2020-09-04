--- src/optionlexer.l.orig	2007-08-14 20:12:44 UTC
+++ src/optionlexer.l
@@ -40,7 +40,7 @@
 #include "optionlexer.h"
 
 char* option_filename;
-YYLTYPE option_lloc;
+extern YYLTYPE option_lloc;
 
 void option_locate();
 %}
