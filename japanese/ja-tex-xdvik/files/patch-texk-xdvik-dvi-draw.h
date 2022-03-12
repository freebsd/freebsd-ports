--- texk/xdvik/dvi-draw.h.orig	2013-04-05 00:14:54 UTC
+++ texk/xdvik/dvi-draw.h
@@ -82,6 +82,11 @@ extern void src_parse(const char *str, i
 #define XX      currinf.data.x
 #define YY      currinf.data.y
 #define ZZ      currinf.data.z
+#ifdef PTEX
+#define TATE    currinf.data.tdir
+#else /* !PTEX */
+#define TATE    False
+#endif /* !PTEX */
 
 extern void draw_page(void);
 extern void source_reverse_search(int, int, wide_bool);
@@ -120,6 +125,13 @@ extern setcharRetvalT set_char(
 			       wide_ubyte cmd,
 #endif
 			       wide_ubyte ch);
+#ifdef PTEX
+extern setcharRetvalT set_char2(
+#ifdef TEXXET
+				wide_ubyte cmd,
+#endif
+				wide_ubyte ch);
+#endif /* PTEX */
 extern setcharRetvalT load_n_set_char(
 #ifdef TEXXET
 				      wide_ubyte cmd,
