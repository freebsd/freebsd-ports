--- Makefile.PL.orig	2011-10-23 12:27:21.000000000 +0200
+++ Makefile.PL	2017-06-03 21:50:44.801687000 +0200
@@ -68,13 +68,8 @@
       next if ! -f $libfile;
       my $include_path = $possible_install_paths{$install_path};
       foreach my $c_header(@c_header_files) {
-        if (-f "$include_path/$c_header") {
+        if (-f "$include_path/js-1.7/$c_header") {
           my $include_dir = "$include_path/$c_header";
-          $include_dir =~ s/$c_header$//;
-          push @JS_INCL_DIRS, $include_dir;
-        }
-        foreach my $headerfile(glob "$include_path/*/$c_header") {
-          my $include_dir = $headerfile;
           $include_dir =~ s/$c_header$//;
           push @JS_INCL_DIRS, $include_dir;
         }
