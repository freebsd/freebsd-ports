--- Makefile.PL.orig	2009-05-22 09:50:05.000000000 +0900
+++ Makefile.PL	2009-06-07 07:15:49.000000000 +0900
@@ -115,17 +115,17 @@
 # and make sure that the user doesn't have any existing CPAN config that'll
 # cause us problems for the next few steps.
 require CPAN::HandleConfig;
-CPAN::HandleConfig->load;
+#CPAN::HandleConfig->load;
 for my $eumm_setting ( qw/makepl_arg make_install_arg/ ) {
-    if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
-        die "Possibly invalid config detected in $eumm_setting: " . $CPAN::Config->{$eumm_setting};
-    }
+#    if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
+#        die "Possibly invalid config detected in $eumm_setting: " . $CPAN::Config->{$eumm_setting};
+#    }
 }
 
 for my $mb_setting (qw/mbuild_arg mbuild_install_arg mbuildpl_arg/) {
-    if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
-        die "Possibly invalid config detected in $mb_setting: " . $CPAN::Config->{$mb_setting};
-    }
+#    if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
+#        die "Possibly invalid config detected in $mb_setting: " . $CPAN::Config->{$mb_setting};
+#    }
 }
 
 if ($bootstrapping) {
