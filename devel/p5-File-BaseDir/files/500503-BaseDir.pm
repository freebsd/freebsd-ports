--- BaseDir.pm.orig	Sun Aug 22 11:18:29 2004
+++ BaseDir.pm	Sun Aug 22 11:20:04 2004
@@ -5,26 +5,28 @@
 require File::Spec;
 require Exporter;
 
-our @ISA = qw(Exporter);
-our @EXPORT_OK = qw(
+use vars qw(@ISA @EXPORT_OK $VERSION);
+@ISA = qw(Exporter);
+@EXPORT_OK = qw(
 	xdg_data_home xdg_data_dirs xdg_data_files
 	xdg_config_home xdg_config_dirs xdg_config_files
 	xdg_cache_home
 );
-our $VERSION = 0.02;
+$VERSION = 0.02;
 
 my $rootdir = File::Spec->rootdir();
 
-our $xdg_data_home = File::Spec->catdir($ENV{HOME}, qw/.local share/);
-our @xdg_data_dirs = (
+use vars qw($xdg_data_home @xdg_data_dirs $xdg_config_home  @xdg_config_dirs $xdg_cache_home);
+$xdg_data_home = File::Spec->catdir($ENV{HOME}, qw/.local share/);
+@xdg_data_dirs = (
 	File::Spec->catdir($rootdir, qw/usr local share/),
 	File::Spec->catdir($rootdir, qw/usr share/),
 );
 
-our $xdg_config_home = File::Spec->catdir($ENV{HOME}, '.config');
-our @xdg_config_dirs = ( File::Spec->catdir($rootdir, qw/etc xdg/) );
+$xdg_config_home = File::Spec->catdir($ENV{HOME}, '.config');
+@xdg_config_dirs = ( File::Spec->catdir($rootdir, qw/etc xdg/) );
 
-our $xdg_cache_home = File::Spec->catdir($ENV{HOME}, '.cache');
+$xdg_cache_home = File::Spec->catdir($ENV{HOME}, '.cache');
 
 sub new { bless \$VERSION, shift } # what else is there to bless ?
 
