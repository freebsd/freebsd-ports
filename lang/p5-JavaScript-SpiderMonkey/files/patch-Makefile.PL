--- Makefile.PL.orig	2010-11-17 13:51:38.000000000 +0100
+++ Makefile.PL	2010-11-17 13:59:54.000000000 +0100
@@ -71,11 +71,6 @@
           $include_dir =~ s/$c_header$//;
           push @JS_INCL_DIRS, $include_dir;
         }
-        foreach my $headerfile(glob "$include_path/*/$c_header") {
-          my $include_dir = $headerfile;
-          $include_dir =~ s/$c_header$//;
-          push @JS_INCL_DIRS, $include_dir;
-        }
       }
       if (scalar(@JS_INCL_DIRS) == scalar(@c_header_files)) {
         $JS_LIB_DIR = $libfile;
