--- flags.h.orig	Thu Jun 15 04:34:11 1995
+++ flags.h	Mon Mar 20 13:29:11 2000
@@ -338,6 +338,10 @@
 
 /* Tag all structures with __attribute__(packed) */
 extern int flag_pack_struct;
+
+/* Nonzero means that -Wformat accepts certain non-ANSI formats.  */
+
+extern int flag_format_extensions;
 
 /* Other basic status info about current function.  */
 
