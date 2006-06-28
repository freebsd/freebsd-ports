--- test/regress.c.orig	Wed Jun 28 22:34:07 2006
+++ test/regress.c	Wed Jun 28 22:34:15 2006
@@ -480,9 +480,9 @@
 
 void
 test_evbuffer(void) {
-	setup_test("Evbuffer: ");
-
 	struct evbuffer *evb = evbuffer_new();
+
+	setup_test("Evbuffer: ");
 
 	evbuffer_add_printf(evb, "%s/%d", "hello", 1);
 
