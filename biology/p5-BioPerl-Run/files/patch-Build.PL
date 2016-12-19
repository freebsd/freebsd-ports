--- Build.PL.orig	2014-07-26 02:49:03 UTC
+++ Build.PL
@@ -50,7 +50,8 @@ my $build = Module::Build->new(
     #create_makefile_pl  => 'passthrough'
 );
 
-my $accept = $build->args->{accept};
+# my $accept = $build->args->{accept};
+my $accept = 1;
 
 # Optionally have script files installed.
 if ($build->args('install_scripts') or $accept ? 0 : $build->y_n("Install scripts? y/n", 'n')) {
