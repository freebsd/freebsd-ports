--- libexplain/output/stderr.h.orig	2020-08-29 10:04:27 UTC
+++ libexplain/output/stderr.h
@@ -22,7 +22,7 @@
 
 #include <libexplain/output.h>
 
-explain_output_t explain_output_static_stderr;
+extern explain_output_t explain_output_static_stderr;
 
 #endif /* LIBEXPLAIN_OUTPUT_STDERR_H */
 /* vim: set ts=8 sw=4 et : */
