--- Gimp.pm.orig	Sat Dec  1 07:35:04 2001
+++ Gimp.pm	Thu Apr 11 18:01:20 2002
@@ -392,6 +392,7 @@
 sub callback {
    my $type = shift;
    my @cb;
+   my @res;
    if ($type eq "-run") {
       local $function = shift;
       local $in_run = 1;
@@ -405,9 +406,7 @@
          );
       }
       die_msg __"required callback 'run' not found\n" unless @cb;
-      my @res;
       for (@cb) { @res = &$_ }
-      return wantarray ? @res : $res[0];
    } elsif ($type eq "-net") {
       local $in_net = 1;
       _initialized_callback;
@@ -420,7 +419,7 @@
          );
       }
       die_msg __"required callback 'net' not found\n" unless @cb;
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    } elsif ($type eq "-query") {
       local $in_query = 1;
       _initialized_callback;
@@ -431,7 +430,7 @@
          );
       }
       die_msg __"required callback 'query' not found\n" unless @cb;
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    } elsif ($type eq "-quit") {
       local $in_quit = 1;
       {
@@ -440,8 +439,9 @@
             @{$callback{quiet}},
          );
       }
-      for (@cb) { &$_ }
+      for (@cb) { @res = &$_ }
    }
+   return (wantarray) ? @res : $res[0];
 }
 
 sub register_callback($$) {
