--- client/mysql.cc.orig	Sun Oct 24 15:54:36 2004
+++ client/mysql.cc	Sun Oct 24 15:55:52 2004
@@ -294,7 +294,7 @@
  HIST_ENTRY is defined for libedit, but not for the real readline
  Need to redefine it for real readline to find it
 */
-#if !defined(USE_LIBEDIT_INTERFACE)
+#if !defined(HAVE_HIST_ENTRY)
 typedef struct _hist_entry {
   const char      *line;
   const char      *data;
