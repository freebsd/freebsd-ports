--- src/java.base/unix/native/libjava/childproc.h.orig	2020-07-15 18:00:08 UTC
+++ src/java.base/unix/native/libjava/childproc.h
@@ -118,7 +118,7 @@ typedef struct _SpawnInfo {
  * The cached and split version of the JDK's effective PATH.
  * (We don't support putenv("PATH=...") in native code)
  */
-const char * const *parentPathv;
+extern const char * const *parentPathv;
 
 ssize_t restartableWrite(int fd, const void *buf, size_t count);
 int restartableDup2(int fd_from, int fd_to);
