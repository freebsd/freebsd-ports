--- client/mysql.cc.orig	Wed Jun  2 09:11:24 2004
+++ client/mysql.cc	Wed Jun  2 09:13:19 2004
@@ -294,7 +294,7 @@
  HIST_ENTRY is defined for libedit, but not for the real readline
  Need to redefine it for real readline to find it
 */
-#if !defined(USE_LIBEDIT_INTERFACE)
+#if !defined(HIST_ENTRY)
 typedef struct _hist_entry {
   const char      *line;
   const char      *data;
