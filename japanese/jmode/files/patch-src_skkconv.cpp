--- src/skkconv.cpp.orig	2002-06-15 14:35:40 UTC
+++ src/skkconv.cpp
@@ -101,7 +101,7 @@ void SKKConv::init()
     bind_str_to_atom("slash", A_skk_begin_latin_conv);
 }
 
-char **SKKConv::getIcon()
+const char **SKKConv::getIcon()
 {
     return skk_xpm;
 }
@@ -960,7 +960,7 @@ void SKKChildWindow::draw()
 void SKKChildWindow::activate(GtkWidget *w, gpointer p)
 {
     SKKChildContext *c;
-    int pos = (int)p;
+    int pos = (uint64_t)p;
     c = get_current_context();
     if (c) {
 	c->stat.setMode(pos);
