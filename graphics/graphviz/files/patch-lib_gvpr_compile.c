--- lib/gvpr/compile.c.orig	2023-09-11 18:30:04 UTC
+++ lib/gvpr/compile.c
@@ -56,7 +56,7 @@ static Sflong_t ptr2int(const void *p) {
 
 static int iofread(void *chan, char *buf, int bufsize)
 {
-  return (int)read(fileno(chan), buf, bufsize);
+  return (int)read(fileno((FILE *)chan), buf, bufsize);
 }
 
 static int ioputstr(void *chan, const char *str)
