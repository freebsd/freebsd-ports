--- src/misc/global.h.orig	Sun Mar  2 05:00:21 2003
+++ src/misc/global.h	Sat Jun 26 09:38:04 2004
@@ -27,14 +27,14 @@
 extern char *winhelpfile;
 extern char *winhelpfile2;
 
-#define DEFAULT_INFORMHOST "inform.invisiblenet.net"
+#define DEFAULT_INFORMHOST "www.invisiblechat.com"
 #define DEFAULT_INFORMPORT 80
-#define DEFAULT_INFORMPAGE "/iiprelays/submitrelay.php"
+#define DEFAULT_INFORMPAGE "/ic/submitrelay.php"
 
-#define DEFAULT_REFGETHOST "www.invisiblenet.net"
+#define DEFAULT_REFGETHOST "www.invisiblechat.com"
 #define DEFAULT_REFGETPORT 80
-#define DEFAULT_REFGETPAGE "/iip/crypto/node.ref"
-#define DEFAULT_REFGETPUBLICRELAYPAGE "/iip/crypto/node.ref"
+#define DEFAULT_REFGETPAGE "/ic/node.ref"
+#define DEFAULT_REFGETPUBLICRELAYPAGE "/ic/node.ref"
 
 extern char *informhost;
 extern int informport;
