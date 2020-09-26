--- ../t4k_common-0.1.1/src/t4k_common.h.orig	2011-03-25 00:35:15.000000000 +0100
+++ ../t4k_common-0.1.1/src/t4k_common.h	2020-09-26 12:24:04.794856000 +0200
@@ -239,7 +239,7 @@
 #define MAX_LINES 128     //!< Maximum lines to wrap.
 #define MAX_LINEWIDTH 256 //!< Maximum characters of each line.
 
-char wrapped_lines[MAX_LINES][MAX_LINEWIDTH]; //!< Global buffer for wrapped lines.
+extern char wrapped_lines[MAX_LINES][MAX_LINEWIDTH]; //!< Global buffer for wrapped lines.
 
 //TODO separate headers for different areas a la SDL?
 
