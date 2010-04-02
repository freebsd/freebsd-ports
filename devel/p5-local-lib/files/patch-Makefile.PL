--- Makefile.PL.orig	2010-03-31 23:38:43.000000000 +0900
+++ Makefile.PL	2010-04-02 07:39:02.544869533 +0900
@@ -201,25 +201,25 @@
     # otherwise, if we're running from CPAN then it will be installed soon
     # enough, and we'll come back here..
     if (!$@) {
-        CPAN::HandleConfig->load;
+        #CPAN::HandleConfig->load;
         for my $eumm_setting ( qw/makepl_arg make_install_arg/ ) {
-            if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
-                die <<"DEATH";
-WHOA THERE! It looks like you've got $CPAN::Config->{$eumm_setting} set. This is
-known to cause problems with local::lib. Please either remove this setting or
-clear out your .cpan directory.
-DEATH
-            }
+#            if ($CPAN::Config->{$eumm_setting} =~ /(?:PREFIX|INSTALL_BASE)/) {
+#                die <<"DEATH";
+#WHOA THERE! It looks like you've got $CPAN::Config->{$eumm_setting} set. This is
+#known to cause problems with local::lib. Please either remove this setting or
+#clear out your .cpan directory.
+#DEATH
+#            }
         }
 
         for my $mb_setting (qw/mbuild_arg mbuild_install_arg mbuildpl_arg/) {
-            if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
-                die <<"DEATH";
-WHOA THERE! It looks like you've got $CPAN::Config->{$mb_setting} set. This is
-known to cause problems with local::lib. Please either remove this setting or
-clear out your .cpan directory.
-DEATH
-            }
+#            if ($CPAN::Config->{$mb_setting} =~ /(?:--prefix|--install_base)/) {
+#                die <<"DEATH";
+#WHOA THERE! It looks like you've got $CPAN::Config->{$mb_setting} set. This is
+#known to cause problems with local::lib. Please either remove this setting or
+#clear out your .cpan directory.
+#DEATH
+#            }
         }
     }
     else {
