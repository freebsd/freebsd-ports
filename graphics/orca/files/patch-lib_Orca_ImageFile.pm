--- lib/Orca/ImageFile.pm    2005/07/11 05:21:08     461
+++ lib/Orca/ImageFile.pm    2005/07/21 02:48:44     467
@@ -400,6 +400,14 @@
 
   my $plot_ref = $self->[I_PLOT_REF];
 
+  # An incompatible change was introduced in RRDtool 1.2 where colons
+  # in COMMENT arguments to RRDs::graph must be escaped with a
+  # backslash.
+  my $plot_end_time_ctime = localtime($plot_end_time);
+  if ($RRDs::VERSION >= 1.2) {
+    $plot_end_time_ctime =~ s/:/\\:/g;
+  }
+
   my ($graph_return, $image_width, $image_height) =
     RRDs::graph
       $image_filename,
@@ -410,7 +418,7 @@
       '-w', $plot_ref->{plot_width},
       '-h', $plot_ref->{plot_height},
       'COMMENT:\s',
-      'COMMENT:Last data entered at ' . localtime($plot_end_time) . '.';
+      "COMMENT:Last data entered at $plot_end_time_ctime.";
   if (my $error = RRDs::error) {
     warn "$0: warning: cannot create '$image_filename': $error\n";
     return;

