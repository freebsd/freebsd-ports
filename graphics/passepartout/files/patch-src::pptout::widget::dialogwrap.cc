--- src/pptout/widget/dialogwrap.cc.orig	Thu Aug 19 00:18:05 2004
+++ src/pptout/widget/dialogwrap.cc	Thu Aug 19 00:19:35 2004
@@ -24,9 +24,9 @@
   Gtk::Button *b = manage(button);
   // Note: It seems that activate means "in any way except a simple click".
   // So we have to add callbacks for both activate and clicked.
-  b->signal_clicked().connect(bind(slot(*this, &Gtk::Dialog::on_response),
+  b->signal_clicked().connect(bind(slot(*this, &DialogWrap::on_response),
 				   action_id));
-  b->signal_activate().connect(bind(slot(*this, &Gtk::Dialog::on_response),
+  b->signal_activate().connect(bind(slot(*this, &DialogWrap::on_response),
 				    action_id));
   return b;
 }
