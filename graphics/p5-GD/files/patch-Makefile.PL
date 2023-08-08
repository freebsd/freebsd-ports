--- Makefile.PL.orig	2023-05-29 07:07:19 UTC
+++ Makefile.PL
@@ -22,25 +22,6 @@ my ($options,$lib_gd_path,$lib_ft_path,$lib_png_path,$
     $lib_tiff_path,$lib_webp_path,$lib_raqm_path,$lib_heif_path,$lib_avif_path,
     $lib_zlib_path,$lib_fontconfig_path,$force,$FCGI,$gdlib_config_path);
 
-use Getopt::Long;
-my $result = GetOptions("ignore_missing_gd" => \$force,
-                        "options=s"       => \$options,
-			"lib_gd_path=s"   => \$lib_gd_path,
-			"lib_ft_path=s"   => \$lib_ft_path,
-			"lib_png_path=s"  => \$lib_png_path,
-			"lib_jpeg_path=s" => \$lib_jpeg_path,
-			"lib_tiff_path=s" => \$lib_tiff_path,
-			"lib_xpm_path=s"  => \$lib_xpm_path,
-			"lib_webp_path=s" => \$lib_webp_path,
-			"lib_raqm_path=s" => \$lib_raqm_path,
-			"lib_heif_path=s" => \$lib_heif_path,
-			"lib_avif_path=s" => \$lib_avif_path,
-			"lib_zlib_path=s" => \$lib_zlib_path,
-                        "lib_fontconfig_path=s" => \$lib_fontconfig_path,
-                        "gdlib_config_path=s" => \$gdlib_config_path,
-                        "fcgi"            => \$FCGI,
-		       );
-
 unless (try_to_autoconfigure() || $force) {
     die <<END;
 **UNRECOVERABLE ERROR**
@@ -60,40 +41,6 @@ END
 if (-d '/usr/lib64') {
   my @libs64 = map {my $a = $_; $a=~ s/lib$/lib64/; $a} @LIBPATH;
   @LIBPATH = (@LIBPATH,@libs64);
-}
-
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
-     --options       "JPEG,GD2,FT,PNG,WEBP,GIF,XPM,GIFANIM,WBMP,BMP" feature options, separated by commas
-     --lib_gd_path   path            path to libgd (/usr/lib)
-     --lib_ft_path   path            path to Freetype library (/usr)
-     --lib_png_path  path            path to libpng (/usr)
-     --lib_jpeg_path path            path to libjpeg (/usr)
-     --lib_xpm_path  path            path to libxpm (/usr)
-     --lib_tiff_path  path           path to libtiff (/usr)
-     --lib_webp_path  path           path to libwebp (/usr)
-     --lib_raqm_path  path           path to libraqm (/usr)
-     --lib_heif_path  path           path to libheif (/usr)
-     --lib_avif_path  path           path to libavif (/usr)
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
 }
 
 if( defined($options) )
