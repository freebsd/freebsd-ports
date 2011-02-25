--- Makefile.PL.orig	2011-02-18 12:54:09.000000000 +0900
+++ Makefile.PL	2011-02-25 22:58:31.891737737 +0900
@@ -209,8 +209,8 @@
     # otherwise, if we're running from CPAN then it will be installed soon
     # enough, and we'll come back here..
     if (!$@ ) {
-        CPAN::HandleConfig->require_myconfig_or_config;
-        if ( $CPAN::Config ) {
+#        CPAN::HandleConfig->require_myconfig_or_config;
+        if ( 0 and $CPAN::Config ) {
             for my $eumm_setting ( qw/makepl_arg make_install_arg/ ) {
                 if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
                     die <<"DEATH";
