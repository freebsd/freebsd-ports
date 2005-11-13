--- src/main.c.orig	Sun Nov  6 21:26:45 2005
+++ src/main.c	Sun Nov 13 02:57:57 2005
@@ -115,6 +115,7 @@
   WrapperEntry *wrapent = NULL;
 
   home = g_strdup_printf("%s/.xarchive/wrappers", getenv("HOME"));
+  {
   char *dir[] = 
     { 
       home, 
@@ -145,6 +146,7 @@
   if (WRAPPER_ARRAY == NULL) 
   {
     g_print("No wrappers found\n");
+  }
   }
 } 
 
