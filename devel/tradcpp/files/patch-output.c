--- ./output.c.orig	2013-06-11 06:14:31.000000000 +0200
+++ ./output.c	2013-06-11 14:19:53.285452684 +0200
@@ -96,7 +96,7 @@
 
 static
 void
-filter_output(const struct place *p, const char *buf, size_t len)
+filter_output(const struct place *p __unused, const char *buf, size_t len)
 {
 	size_t pos, start;
 	bool inesc = false;
