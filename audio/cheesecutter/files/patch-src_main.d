--- src/main.d.orig	2020-12-25 15:36:31 UTC
+++ src/main.d
@@ -23,6 +23,10 @@ version(linux) {
 	const DIR_SEPARATOR = '/';
 }
 
+version(FreeBSD) {
+	const DIR_SEPARATOR = '/';
+}
+
 version(OSX) {
 	const DIR_SEPARATOR = '/';
 }
