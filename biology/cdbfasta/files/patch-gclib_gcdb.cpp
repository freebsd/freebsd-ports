--- gclib/gcdb.cpp.orig	2023-07-10 09:57:25 UTC
+++ gclib/gcdb.cpp
@@ -99,7 +99,7 @@ static unsigned int gcdb_strlen(const char *s) {
 #define gcdb_seek_begin(fd) (gcdb_seek_set((fd),(gcdb_seek_pos) 0))
 
 static unsigned int gcdb_strlen(const char *s) {
-  register char *t;
+  char *t;
   t = (char*)s;
   for (;;) {
     if (!*t) return t - s;
