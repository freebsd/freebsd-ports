--- lib/japanese.sl.orig	1999-07-23 12:05:25 UTC
+++ lib/japanese.sl
@@ -5,8 +5,10 @@
 %
 
 
-define	TRUE()	{ -1;}
-define	FALSE()	{ 0;}
+!if (is_defined("TRUE")) {
+	eval("define	TRUE()	{ -1;}");
+	eval("define	FALSE()	{ 0;}");
+}
 
 % If your slang-j's version in jed-j is after 0.3.2,
 % you can use KANJI function name.
