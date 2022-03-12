--- texk/xdvik/ptexmap.h.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ptexmap.h
@@ -0,0 +1,27 @@
+#ifndef PTEXMAP_H_
+#define PTEXMAP_H_
+
+#ifdef PTEX
+struct ptexmap {
+    char *jfm_name;
+    char *font_filename;
+    int ft2_index;
+    int face_index;
+    enum { ENC_UNKNOWN, ENC_JIS_H, ENC_JIS_V, ENC_UNICODE_H, ENC_UNICODE_V,
+	   ENC_AJ16_H, ENC_AJ16_V, 
+	   ENC_IDENTITY } encoding;
+    enum { VAR_BOLD = 0x01, VAR_ITALIC = 0x02 } variant;
+    float extend, slant;
+    char *sfd_name;
+    char *csi;
+    char *map_filename; /* only for warning message */
+};
+
+void read_ptexmap_file(char *filename);
+struct ptexmap *getkanjifont(const char *jfm_name);
+#define iskanjifont(jfm_name) (getkanjifont(jfm_name) != NULL)
+
+void add_replace_dictionary(char *key, char *word);
+#endif	/* PTEX */
+
+#endif /* PTEXMAP_H_ */
