--- search.c.orig	2008-11-07 15:50:57 UTC
+++ search.c
@@ -30,6 +30,18 @@ static int searchA(char **string, int *s
   if (!ask_about_save_and_redisplay()) return FALSE;
   if (!displayMessageAndGetString(msg, last, tmp, tmp_size)) return FALSE;
 
+  if( hexOrAscii ) {
+    char* cp = tmp;
+    char* cp2 = tmp;
+    char  c;
+    while( (c = *cp++) ) {
+      if( isspace( c ) )
+        continue;
+      *cp2++ = c;
+    }
+    *cp2 = '\0';
+  }
+
   *sizea = strlen(tmp);
   if (hexOrAscii) if (!hexStringToBinString(tmp, sizea)) return FALSE;
 
