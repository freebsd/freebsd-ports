
$FreeBSD$

--- objects/GRAFCET/boolequation.c	2002/07/12 11:18:01	1.1
+++ objects/GRAFCET/boolequation.c	2002/07/12 11:24:38
@@ -64,7 +64,7 @@
 
 
 /* utility */
-inline static gboolean isspecial(unichar c) 
+inline static gboolean dia_isspecial(unichar c) 
 {
   switch (c) {
   case '!':
@@ -141,7 +141,7 @@
     c = g_utf8_get_char(*str);
     p1 = g_utf8_next_char(*str);
 #endif
-    if (isspecial(c)) break;
+    if (dia_isspecial(c)) break;
     *str = p1;
   }
   
