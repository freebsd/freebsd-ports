--- app/menus.c.orig
+++ app/menus.c
@@ -1597,7 +1597,7 @@
 char*
 menu_entry_translate (const char* entry)
 {
-  char *text = (char*) calloc (1024, sizeof(char)),
+  char *text = (char*) calloc (sizeof(char), 1024),
        *word = 0;
   const char *tmp = 0;
 
@@ -1647,11 +1647,11 @@
   // resize memory
   if(strlen(text))
   {
-    word = (char*) calloc( strlen(text) + 1, sizeof(char) );
+    word = (char*) calloc( sizeof(char), strlen(text) + 4 );
     memcpy( word, text, strlen( text ) + 1 );
     free (text);
     return word;
   }
   else
-    return (char*) calloc(1,sizeof(char));
+    return (char*) calloc(sizeof(char),1);
 }
