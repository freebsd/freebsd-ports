--- src/ui/widget/registered-widget.h.orig	2013-10-17 12:28:59.000000000 +0200
+++ src/ui/widget/registered-widget.h	2013-10-17 12:36:51.000000000 +0200
@@ -61,9 +61,6 @@
 
     bool is_updating() {if (_wr) return _wr->isUpdating(); else return false;}
 
-    // provide automatic 'upcast' for ease of use. (do it 'dynamic_cast' instead of 'static' because who knows what W is)
-    operator const Gtk::Widget () { return dynamic_cast<Gtk::Widget*>(this); }
-
 protected:
     RegisteredWidget() : W() { construct(); }
     template< typename A >
