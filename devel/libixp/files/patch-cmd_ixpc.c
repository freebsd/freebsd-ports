--- cmd/ixpc.c.orig	2008-09-21 03:39:51 UTC
+++ cmd/ixpc.c
@@ -14,6 +14,7 @@
 #define fatal(...) ixp_eprint("ixpc: fatal: " __VA_ARGS__); \
 
 static IxpClient *client;
+char *argv0;
 
 static void
 usage(void) {
