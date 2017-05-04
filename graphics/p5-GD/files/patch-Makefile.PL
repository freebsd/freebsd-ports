--- Makefile.PL.orig	2017-04-23 12:06:14 UTC
+++ Makefile.PL
@@ -20,20 +20,6 @@ my $AUTOCONFIG = 0;      # global set by
 my ($options,$lib_gd_path,$lib_ft_path,$lib_png_path,$lib_jpeg_path,$lib_xpm_path,
     $lib_zlib_path,$lib_fontconfig_path,$force,$FCGI,$gdlib_config_path);
 
-use Getopt::Long;
-my $result = GetOptions("ignore_missing_gd" => \$force,
-                        "options=s"       => \$options,
-			"lib_gd_path=s"   => \$lib_gd_path,
-			"lib_ft_path=s"   => \$lib_ft_path,
-			"lib_png_path=s"  => \$lib_png_path,
-			"lib_jpeg_path=s" => \$lib_jpeg_path,
-			"lib_xpm_path=s"  => \$lib_xpm_path,
-			"lib_zlib_path=s" => \$lib_zlib_path,
-                        "lib_fontconfig_path=s" => \$lib_fontconfig_path,
-                        "gdlib_config_path=s" => \$gdlib_config_path,
-                        "fcgi"            => \$FCGI,
-		       );
-
 unless (try_to_autoconfigure() || $force) {
     die <<END;
 **UNRECOVERABLE ERROR**
@@ -57,35 +43,6 @@ if (-d '/usr/lib64') {
   @LIBPATH = (@LIBPATH,@libs64);
 }
 
-#############################################################################################
-# Build options passed in to script to support reproducible builds via Makefiles
-#############################################################################################
-unless ($result) {
-  print STDERR <<END;
-Usage: perl Makefile.PL [options]
-
-Configure GD module.
-
- Options:
-     --options       "JPEG,FT,PNG,GIF,XPM,ANIMGIF"   feature options, separated by commas
-     --lib_gd_path   path            path to libgd (/usr/lib)
-     --lib_ft_path   path            path to Freetype library (/usr)
-     --lib_png_path  path            path to libpng (/usr)
-     --lib_jpeg_path path            path to libjpeg (/usr)
-     --lib_xpm_path  path            path to libxpm (/usr)
-     --lib_zlib_path path            path to libpng (/usr)
-     --lib_fontconfig_path path      path to libfontconfig (/usr)
-     --gdlib_config_path path        path to gdlib-config (/usr/bin)
-     --ignore_missing_gd             Ignore missing or old libgd installations and try to compile anyway
-     --fcgi                          build for FastCGI compatibility, i.e. no PerlIO
-
-If no options are passed on the command line.  The program will
-attempt to autoconfigure itself with the gdlib-config program or pkgconfig/gdlib.pc
-(present in GD versions 2.0.27 or later).  Otherwise it will prompt for these
-values interactively.
-END
-}
-
 if( defined($options) )
 {
     print "Included Features:          $options\n";
