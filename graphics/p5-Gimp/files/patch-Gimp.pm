--- Gimp.pm.orig	Sat Dec  1 07:35:04 2001
+++ Gimp.pm	Wed Apr 17 10:00:58 2002
@@ -200,6 +200,7 @@
    if ($gtk_init) {
       require Gtk;
+      Gtk->set_locale;
       Gtk->init;
       Gtk::Rc->parse (Gimp->gtkrc);
       Gtk::Gdk->set_use_xshm (Gimp->use_xshm);
       Gtk::Preview->set_gamma (Gimp->gamma);
@@ -392,6 +393,7 @@
 sub callback {
    my $type = shift;
    my @cb;
+   my @res;
    if ($type eq "-run") {
       local $function = shift;
       local $in_run = 1;
@@ -405,9 +407,7 @@
          );
       }
       die_msg __"required callback 'run' not found\n" unless @cb;
-      my @res;
       for (@cb) { @res = &$_ }
-      return wantarray ? @res : $res[0];
    } elsif ($type eq "-net") {
       local $in_net = 1;
       _initialized_callback;
@@ -420,7 +420,7 @@
          );
       }
       die_msg __"required callback 'net' not found\n" unless @cb;
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    } elsif ($type eq "-query") {
       local $in_query = 1;
       _initialized_callback;
@@ -431,7 +431,7 @@
          );
       }
       die_msg __"required callback 'query' not found\n" unless @cb;
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    } elsif ($type eq "-quit") {
       local $in_quit = 1;
       {
@@ -440,8 +440,9 @@
             @{$callback{quiet}},
          );
       }
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    }
+   return (wantarray) ? @res : $res[0];
 }
 
 sub register_callback($$) {
