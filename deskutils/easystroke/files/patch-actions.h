Fix build with libsigc++ 2.4+ (group was removed).

https://aur.archlinux.org/cgit/aur.git/commit/sigc.patch?h=easystroke-git&id=3d16f0584c8cf0ade6c181cb56c12d7abe2e17b7

--- actions.h.orig	2013-03-27 15:52:38 UTC
+++ actions.h
@@ -31,6 +31,11 @@ class TreeViewMulti : public Gtk::TreeView {
 	virtual void on_drag_begin(const Glib::RefPtr<Gdk::DragContext> &context);
 public:
 	TreeViewMulti();
+    bool negate_pending(const Glib::RefPtr<Gtk::TreeModel>& model,
+                        const Gtk::TreeModel::Path& path,
+                        bool path_currently_selected) {
+        return !pending;
+    }
 };
 
 class Actions {
