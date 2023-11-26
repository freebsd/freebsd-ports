--- lib/gvpr/actions.c.orig	2023-09-11 18:30:04 UTC
+++ lib/gvpr/actions.c
@@ -33,7 +33,7 @@
 #define KINDS(p) ((AGTYPE(p) == AGRAPH) ? "graph" : (AGTYPE(p) == AGNODE) ? "node" : "edge")
 
 static int iofread(void *chan, char *buf, int bufsize) {
-  return (int)read(fileno(chan), buf, bufsize);
+  return (int)read(fileno((FILE *)chan), buf, bufsize);
 }
 
 static int ioputstr(void *chan, const char *str) {
