--- Makefile.PL.orig	2009-06-18 07:54:34.000000000 +0900
+++ Makefile.PL	2009-06-18 07:56:03.000000000 +0900
@@ -125,17 +125,17 @@
     # otherwise, if we're running from CPAN then it will be installed soon
     # enough, and we'll come back here..
     if (!$@) {
-        CPAN::HandleConfig->load;
+        #CPAN::HandleConfig->load;
         for my $eumm_setting ( qw/makepl_arg make_install_arg/ ) {
-            if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
-                die "Possibly invalid config detected in $eumm_setting: " . $CPAN::Config->{$eumm_setting};
-            }
+#            if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
+#                die "Possibly invalid config detected in $eumm_setting: " . $CPAN::Config->{$eumm_setting};
+#            }
         }
 
         for my $mb_setting (qw/mbuild_arg mbuild_install_arg mbuildpl_arg/) {
-            if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
-                die "Possibly invalid config detected in $mb_setting: " . $CPAN::Config->{$mb_setting};
-            }
+#            if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
+#                die "Possibly invalid config detected in $mb_setting: " . $CPAN::Config->{$mb_setting};
+#            }
         }
     }
     else {
