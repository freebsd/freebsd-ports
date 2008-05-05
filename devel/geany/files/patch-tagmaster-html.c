--- tagmanager/html.c.orig	2008-04-26 03:13:29.000000000 +0300
+++ tagmanager/html.c	2008-04-26 03:13:42.000000000 +0300
@@ -31,7 +31,7 @@
 
 /* this matches simple heading without nested tags */
 /** TODO combine both pattern to be able to match both heading styles */
-#define INNER_HEADING "[ \t]*(.*+)[ \t]*"
+#define INNER_HEADING "[ \t]*(.+)[ \t]*"
 
 	addTagRegex (language,
 		"<a"
