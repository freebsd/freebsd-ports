Add minimal support to `pkg-config imlib2`; imlib2-config has been
dropped since imlib2-1.7.5.

--- Build.PL.orig	2009-11-24 21:41:36 UTC
+++ Build.PL
@@ -1,26 +1,8 @@ use strict;
 use Module::Build;
 use strict;
 
-# We need to find imlib2-config
-my $CONFIG = "imlib2-config";
-
-my $version = `$CONFIG --version`;
-if (!$version) {
-  warn 'You must install the imlib2 library before you can install
-Image::Imlib2. You can obtain imlib2 from
-http://sourceforge.net/projects/enlightenment/
-
-Alternatively, if you have downloaded and installed imlib2 and this
-still will not work, modify the $CONFIG variable inside Build.PL to
-point to the imlib2-config program that provides.
-';
-  exit 0;
-} else {
-  print "Found imlib2 $version";
-}
-
-my $libs = `$CONFIG --libs`;
-my $cflags = "-DX_DISPLAY_MISSING " . `$CONFIG --cflags`;
+my $libs = `pkg-config --libs imlib2`;
+my $cflags = "-DX_DISPLAY_MISSING " . `pkg-config --cflags imlib2`;
 
 my $build = Module::Build->new(
   c_source     => './lib/Image',
