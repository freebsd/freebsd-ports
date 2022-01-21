- workaround for https://bitbucket.org/agriggio/art/issues/227 caused by https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=261360

--- rtgui/main.cc.orig	2022-01-20 17:14:43 UTC
+++ rtgui/main.cc
@@ -370,6 +370,8 @@ void show_gimp_plugin_info_dialog(Gtk::Window *parent)
 
 int main (int argc, char **argv)
 {
+	setenv("LIBOMP_NUM_HIDDEN_HELPER_THREADS", "0", 1);
+
 #ifdef WITH_MIMALLOC
     mi_version();
 #endif
