--- Makefile.PL.orig	2013-11-06 03:07:13.000000000 +0900
+++ Makefile.PL	2013-11-11 00:55:11.078989410 +0900
@@ -212,8 +212,8 @@
     # otherwise, if we're running from CPAN then it will be installed soon
     # enough, and we'll come back here..
     if (!$@ ) {
-        CPAN::HandleConfig->require_myconfig_or_config;
-        if ( $CPAN::Config ) {
+#        CPAN::HandleConfig->require_myconfig_or_config;
+        if (0 and $CPAN::Config ) {
             for my $setting (qw(
               makepl_arg make_install_arg
               mbuild_arg mbuild_install_arg mbuildpl_arg
