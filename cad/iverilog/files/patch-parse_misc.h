--- parse_misc.h.orig	Sun Dec  1 23:51:26 2002
+++ parse_misc.h	Sun Dec  1 23:56:43 2002
@@ -38,6 +38,9 @@
       const char*text;
 };
 # define YYLTYPE vlltype
+#ifndef yylloc
+#define yylloc VLlloc
+#endif
 extern YYLTYPE yylloc;
 
 /*
