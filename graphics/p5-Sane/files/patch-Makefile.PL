--- Makefile.PL.orig	2009-01-17 23:24:51.000000000 +0800
+++ Makefile.PL	2009-01-17 23:25:01.000000000 +0800
@@ -16,7 +16,7 @@
 # Can't assume ExtUtils::PkgConfig will return anything useful until
 # the pkg-config files ship with sane.
 my $lib = '-lsane';
-my $inc = '-I. ';
+my $inc = '-I. -I${LOCALBASE}/include';
 if (eval {
   %pkgcfg = ExtUtils::PkgConfig->find ('sane-backends >= '. $build_reqs{libsane})
 }) {
