--- inc/Module/Install/XSUtil.pm.orig	2015-04-24 17:35:21 UTC
+++ inc/Module/Install/XSUtil.pm
@@ -242,7 +242,7 @@ sub cc_assert_lib {
 
     if ( ! $self->{xsu_loaded_checklib} ) {
         my $loaded_lib = 0;
-        foreach my $checklib qw(inc::Devel::CheckLib Devel::CheckLib) {
+        foreach my $checklib ( qw(inc::Devel::CheckLib Devel::CheckLib) ) {
             eval "use $checklib 0.4";
             if (!$@) {
                 $loaded_lib = 1;
