--- hexbin/globals.h.orig	Fri Apr 16 00:28:16 1999
+++ hexbin/globals.h	Fri Apr 16 00:28:25 1999
@@ -13,7 +13,7 @@
 extern char info[];
 extern char trname[];
 
-typedef struct macheader {
+struct macheader {
 	char m_name[128];
 	char m_type[4];
 	char m_author[4];
