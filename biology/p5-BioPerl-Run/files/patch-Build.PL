--- ./Build.PL.orig	2014-07-26 04:49:03.000000000 +0200
+++ ./Build.PL	2014-08-04 09:33:15.000000000 +0200
@@ -42,7 +42,8 @@
     #create_makefile_pl  => 'passthrough'
 );
 
-my $accept = $build->args->{accept};
+# my $accept = $build->args->{accept};
+my $accept = 1;
 
 # Optionally have script files installed.
 if ($build->args('install_scripts') or $accept ? 0 : $build->y_n("Install scripts? y/n", 'n')) {
