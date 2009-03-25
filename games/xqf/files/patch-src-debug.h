--- src/debug.h.orig	2004-01-01 15:41:10.000000000 +0300
+++ src/debug.h	2009-03-25 22:03:41.000000000 +0300
@@ -37,7 +37,7 @@
 void debug_int(const char* file, int line, const char* function, int level, const char* fmt, ...);
 void debug_cmd(int, char *[], char *, ...);
 void set_debug_level (int);
-inline int get_debug_level (void);
+int get_debug_level (void);
 
 int debug_increase_indent(void);
 int debug_decrease_indent(void);
