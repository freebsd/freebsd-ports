--- Build.PL.orig	2019-02-08 19:53:38 UTC
+++ Build.PL
@@ -75,7 +75,8 @@ my $build = Module::Build->subclass(
     #create_makefile_pl  => 'passthrough'
 );
 
-my $accept = $build->args->{accept};
+# my $accept = $build->args->{accept};
+my $accept = 1;
 
 # Optionally have script files installed.
 if ($build->args('install_scripts') or $accept ? 0 : $build->y_n("Install scripts? y/n", 'n')) {
