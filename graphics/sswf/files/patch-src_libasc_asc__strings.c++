--- src/libasc/asc_strings.c++.orig	2011-06-21 00:02:53.000000000 +0200
+++ src/libasc/asc_strings.c++	2011-06-21 00:03:42.000000000 +0200
@@ -4009,8 +4009,8 @@
 ;
 }
 
-extern const int files_count = 46;
-extern const char *files[] = {
+const int files_count = 46;
+const char *files[] = {
 	"include/sswf/scripts/extensions/trace.asc", file1,
 	"include/sswf/scripts/extensions/complex.asc", file2,
 	"include/sswf/scripts/global/extensions.asc", file3,
