$FreeBSD$

--- code_usage_dump.c.orig	Wed Dec 15 22:07:02 2004
+++ code_usage_dump.c	Wed Feb  2 22:49:15 2005
@@ -43,0 +44,2 @@
+
+    hashtab* methods;
@@ -53 +55 @@
-    hashtab* methods = get_methods();    
+    methods = get_methods();    
@@ -61 +62,0 @@
-        methods_count = 0;
@@ -62,0 +64 @@
+        methods_count = 0;
