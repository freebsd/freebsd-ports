--- gcc/c-decl.c.orig	Mon Apr 12 07:05:29 1999
+++ gcc/c-decl.c	Sun Nov 26 15:24:45 2000
@@ -557,6 +557,7 @@
 /* Warn about *printf or *scanf format/argument anomalies.  */
 
 int warn_format;
+int warn_format_extra_args;
 
 /* Warn about a subscript that has type char.  */
 
@@ -808,10 +809,17 @@
     warn_traditional = 1;
   else if (!strcmp (p, "-Wno-traditional"))
     warn_traditional = 0;
+  else if (!strcmp (p, "-Wnon-const-format"))
+    warn_format = MAX(warn_format, 2);
   else if (!strcmp (p, "-Wformat"))
-    warn_format = 1;
+    {
+      warn_format_extra_args = 1;
+      warn_format = MAX(warn_format, 1);
+    }
   else if (!strcmp (p, "-Wno-format"))
     warn_format = 0;
+  else if (!strcmp (p, "-Wno-format-extra-args"))
+    warn_format_extra_args = 0;
   else if (!strcmp (p, "-Wchar-subscripts"))
     warn_char_subscripts = 1;
   else if (!strcmp (p, "-Wno-char-subscripts"))
@@ -882,7 +890,7 @@
       warn_return_type = 1;
       warn_unused = 1;
       warn_switch = 1;
-      warn_format = 1;
+      warn_format = MAX(warn_format, 1);
       warn_char_subscripts = 1;
       warn_parentheses = 1;
       warn_missing_braces = 1;
