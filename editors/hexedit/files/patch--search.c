--- search.c.orig	Tue Nov  8 17:16:47 2005
+++ search.c	Sat Jul 29 15:21:47 2006
@@ -30,6 +30,18 @@
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
 
