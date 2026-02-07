--- BPGame.h.orig	2010-03-06 17:50:16.000000000 +0300
+++ BPGame.h	2013-09-13 22:54:50.743226510 +0400
@@ -54,7 +54,7 @@
 class SpriteFont;
 
 struct cmp_str {
-	bool operator()(char const *a, char const *b) {
+	bool operator()(char const *a, char const *b) const {
 		return std::strcmp(a, b) < 0;
 	}
 };
