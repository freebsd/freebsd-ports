--- objects/GRAFCET/boolequation.c.orig	Sun Oct  6 14:55:22 2002
+++ objects/GRAFCET/boolequation.c	Mon Mar 17 13:56:09 2003
@@ -58,7 +58,7 @@
 
 
 /* utility */
-inline static gboolean isspecial(gunichar c) 
+inline static gboolean dia_isspecial(gunichar c) 
 {
   switch (c) {
   case '!':
@@ -136,7 +136,7 @@
     gchar *p1;
     c = g_utf8_get_char(*str);
     p1 = g_utf8_next_char(*str);
-    if (isspecial(c)) break;
+    if (dia_isspecial(c)) break;
     *str = p1;
   }
   
