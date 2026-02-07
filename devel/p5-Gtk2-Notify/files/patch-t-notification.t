--- t/notification.t.orig	2006-08-27 14:11:57.000000000 -0500
+++ t/notification.t	2012-04-29 05:36:50.252318938 -0500
@@ -2,20 +2,18 @@
 
 use strict;
 use warnings;
-use Gtk2::TestHelper tests => 35;
+use Gtk2::TestHelper tests => 32;
 use Test::Exception;
 use Gtk2::Notify -init, $0;
 
 ginterfaces_ok('Gtk2::Notify');
 
-my $w = Gtk2::Window->new;
-my $n = Gtk2::Notify->new('foo', 'bar', '', $w);
+my $n = Gtk2::Notify->new('foo', 'bar', '');
 
 isa_ok($n, 'Gtk2::Notify');
 
 my @methods = qw(
         add_action
-        attach_to_widget
         clear_actions
         clear_hints
         close
@@ -46,16 +44,6 @@ lives_ok(sub {
         }, 42);
 }, 'add_action');
 
-{
-    my $nw = Gtk2::Window->new;
-    lives_ok(sub {
-            $n->attach_to_widget($nw);
-    }, 'attach_to_widget');
-    lives_ok(sub {
-            $n->attach_to_widget($w);
-    }, 'attach_to_widget');
-}
-
 lives_ok(sub {
         $n->clear_actions;
 }, 'clear_actions with existing actions');
@@ -99,8 +87,6 @@ lives_ok(sub {
         $n->close;
 }, 'close before show');
 
-$w->show_all;
-
 lives_ok(sub {
         $n->show;
 }, 'show');
