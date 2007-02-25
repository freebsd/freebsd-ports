--- src/hf/img_process.c.orig	Tue Dec 26 07:44:14 2006
+++ src/hf/img_process.c	Sun Feb 25 01:07:13 2007
@@ -1828,6 +1828,8 @@
 	free(buffer_out);
 }
 
+#define log2(x) log(x)/log(2)
+
 void hf_cut_graph (hf_struct_type *hf, gint index, gint axis) {
 
 	// Draw a graph of line / column "index" on axis "axis"
