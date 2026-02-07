--- lib/SVK/Util.pm.orig	2009-12-21 16:00:13 UTC
+++ lib/SVK/Util.pm
@@ -88,7 +88,7 @@ use File::Glob qw(bsd_glob);
 use autouse 'File::Basename' 	=> qw(dirname);
 use autouse 'File::Spec::Functions' => 
                                qw(catdir catpath splitpath splitdir tmpdir);
-use autouse 'List::Util'        => qw( max(@) );
+use List::Util;
 
 
 =head1 NAME
