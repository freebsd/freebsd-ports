--- Tty.xs.orig	2022-11-11 20:14:48 UTC
+++ Tty.xs
@@ -186,7 +186,7 @@ mysignal(int sig, mysig_t act)
  * will be copied.  Always NUL terminates (unless siz == 0).
  * Returns strlen(src); if retval >= siz, truncation occurred.
  */
-static size_t
+size_t
 strlcpy(dst, src, siz)
         char *dst;
         const char *src;
