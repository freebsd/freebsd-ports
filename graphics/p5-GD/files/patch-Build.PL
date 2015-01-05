--- Build.PL.orig	2014-10-28 01:34:54 UTC
+++ Build.PL
@@ -28,40 +28,6 @@ if (-d '/usr/lib64') {
   @LIBPATH = (@LIBPATH,@libs64);
 }
 
-#############################################################################################
-# Build options passed in to script to support reproducible builds via Makefiles
-#############################################################################################
-my $result = GetOptions("options=s"       => \$options,
-			"lib_gd_path=s"   => \$lib_gd_path,
-			"lib_ft_path=s"   => \$lib_ft_path,
-			"lib_png_path=s"  => \$lib_png_path,
-			"lib_jpeg_path=s" => \$lib_jpeg_path,
-			"lib_xpm_path=s"  => \$lib_xpm_path,
-			"lib_zlib_path=s" => \$lib_zlib_path,
-		       );
-unless ($result) {
-  die <<END;
-Usage: perl Build.PL [options]
-
-Configure GD module.
-
- Options:
-     -options       "JPEG,FT,PNG,GIF,XPM,ANIMGIF"   feature options, separated by commas
-     -lib_gd_path   path            path to libgd
-     -lib_ft_path   path            path to Freetype library
-     -lib_png_path  path            path to libpng
-     -lib_jpeg_path path            path to libjpeg
-     -lib_xpm_path  path            path to libxpm
-     -lib_zlib_path path            path to libpng
-     -ignore_missing_gd             Ignore missing or old libgd installations and try to compile anyway
-
-If no options are passed on the command line.  The program will
-attempt to autoconfigure itself with the gdlib-config program (present
-in GD versions 2.0.27 or later).  Otherwise it will prompt for these
-values interactively.
-END
-}
-
 if( defined($options) )
 {
     print "Included Features:          $options\n";
