Fix build with libsigc++ 2.4+ (group was removed).

https://aur.archlinux.org/cgit/aur.git/commit/sigc.patch?h=easystroke-git&id=3d16f0584c8cf0ade6c181cb56c12d7abe2e17b7

--- actions.cc.orig	2013-03-27 15:52:38 UTC
+++ actions.cc
@@ -51,10 +51,8 @@ void TreeViewMulti::on_drag_begin(const Glib::RefPtr<G
 	context->set_icon(pb, pb->get_width(), pb->get_height());
 }
 
-bool negate(bool b) { return !b; }
-
 TreeViewMulti::TreeViewMulti() : Gtk::TreeView(), pending(false) {
-	get_selection()->set_select_function(sigc::group(&negate, sigc::ref(pending)));
+    get_selection()->set_select_function(sigc::mem_fun(*this, &TreeViewMulti::negate_pending));
 }
 
 enum Type { COMMAND, KEY, TEXT, SCROLL, IGNORE, BUTTON, MISC };
