--- hexbin/globals.h.orig	1993-10-02 20:16:00 UTC
+++ hexbin/globals.h
@@ -13,7 +13,7 @@ extern void transname();
 extern char info[];
 extern char trname[];
 
-typedef struct macheader {
+struct macheader {
 	char m_name[128];
 	char m_type[4];
 	char m_author[4];
