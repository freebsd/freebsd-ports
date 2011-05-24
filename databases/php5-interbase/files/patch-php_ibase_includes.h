--- php_ibase_includes.h.orig	2011-05-24 10:11:01.000000000 +0200
+++ php_ibase_includes.h	2011-05-24 10:11:12.000000000 +0200
@@ -51,7 +51,7 @@
 #define LE_PLINK "Firebird/InterBase persistent link"
 #define LE_TRANS "Firebird/InterBase transaction"
 
-#define IBASE_MSGSIZE 256
+#define IBASE_MSGSIZE 512
 #define MAX_ERRMSG (IBASE_MSGSIZE*2)
 
 #define IB_DEF_DATE_FMT "%Y-%m-%d"
