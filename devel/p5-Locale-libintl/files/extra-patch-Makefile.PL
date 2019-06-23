--- Makefile.PL.orig	2018-10-08 08:37:35 UTC
+++ Makefile.PL
@@ -94,12 +94,6 @@ EOF
 
 my $build_gettext_xs = ac_try_link $c, "Checking whether we can compile the XS version";
 unless ($build_gettext_xs) {
-    $build_gettext_xs = ac_try_link $c, "  Trying again with -lintl", "-lintl";
-}
-unless ($build_gettext_xs) {
-    $build_gettext_xs = ac_try_link $c, "  Trying again with -lintl -liconv", "-lintl", "-liconv";
-}
-unless ($build_gettext_xs) {
     $build_gettext_xs = ac_try_link $c, "  Trying again with -liconv", "-liconv";
 }
 
