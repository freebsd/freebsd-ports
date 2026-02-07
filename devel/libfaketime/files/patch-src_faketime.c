--- src/faketime.c.orig	2025-06-09 12:31:15 UTC
+++ src/faketime.c
@@ -50,7 +50,7 @@ const char version[] = "0.9.12";
 
 const char version[] = "0.9.12";
 
-#if (defined __APPLE__) || (defined __sun)
+#if (defined __APPLE__) || (defined __sun) || defined(__FreeBSD__)
 static const char *date_cmd = "gdate";
 #else
 static const char *date_cmd = "date";
