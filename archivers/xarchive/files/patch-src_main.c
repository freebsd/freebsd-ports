--- src/main.c.orig	2006-02-23 17:25:47 UTC
+++ src/main.c
@@ -115,6 +115,7 @@ setup_wrappers(void)
   WrapperEntry *wrapent = NULL;
 
   home = g_strdup_printf("%s/.xarchive/wrappers", getenv("HOME"));
+  {
   char *dir[] = 
     { 
       home, 
@@ -146,6 +147,7 @@ setup_wrappers(void)
   {
     g_print("No wrappers found\n");
   }
+  }
 } 
 
 extern gchar * 
