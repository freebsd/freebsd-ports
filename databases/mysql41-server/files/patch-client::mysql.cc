--- client/mysql.cc.orig	Mon May 31 18:16:27 2004
+++ client/mysql.cc	Mon May 31 18:24:35 2004
@@ -294,7 +294,7 @@
  HIST_ENTRY is defined for libedit, but not for the real readline
  Need to redefine it for real readline to find it
 */
-#if !defined(USE_LIBEDIT_INTERFACE)
+#if defined(USE_LIBEDIT_INTERFACE)
 typedef struct _hist_entry {
   const char      *line;
   const char      *data;
