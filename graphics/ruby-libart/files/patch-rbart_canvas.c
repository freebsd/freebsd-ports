--- src/rbart_canvas.c.orig	Mon Jan 20 01:04:03 2003
+++ src/rbart_canvas.c	Fri Mar 21 20:06:11 2003
@@ -156,6 +156,7 @@
         return r_self;
 }
 
+#if 0
 static void
 user_init_destination(cinfo)
 	j_compress_ptr cinfo;
@@ -188,6 +189,42 @@
 	r_buffer = (VALUE) cinfo->client_data;
 	RSTRING(r_buffer)->len = RSTRING(r_buffer)->aux.capa - cinfo->dest->free_in_buffer;
 	RSTRING(r_buffer)->ptr[RSTRING(r_buffer)->len] = '\0';
+}
+#endif
+
+struct client_data {
+	VALUE r_result;
+	JOCTET buffer[BUFSIZ];
+};
+
+static void
+user_init_destination(cinfo)
+	j_compress_ptr cinfo;
+{
+	struct client_data *cd;
+	cd = (struct client_data *) cinfo->client_data;
+	cinfo->dest->next_output_byte = cd->buffer;
+	cinfo->dest->free_in_buffer = BUFSIZ;
+}
+
+static boolean
+user_empty_output_buffer(cinfo)
+	j_compress_ptr cinfo;
+{
+	struct client_data *cd;
+	cd = (struct client_data *) cinfo->client_data;
+	rb_str_cat(cd->r_result, cd->buffer, BUFSIZ);
+	cinfo->dest->next_output_byte = cd->buffer;
+	cinfo->dest->free_in_buffer = BUFSIZ;
+}
+
+static void
+user_term_destination(cinfo)
+	j_compress_ptr cinfo;
+{
+	struct client_data *cd;
+	cd = (struct client_data *) cinfo->client_data;
+	rb_str_cat(cd->r_result, cd->buffer, cinfo->dest->next_output_byte - cd->buffer);
 }
 
 static VALUE
