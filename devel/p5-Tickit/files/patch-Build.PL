--- Build.PL.orig	2021-08-18 11:38:08 UTC
+++ Build.PL
@@ -28,8 +28,6 @@ my $build = Module::Build::Using::PkgConfig->new(
 
 $build->use_pkgconfig( "tickit",
    atleast_version => "0.4.2",
-   alien         => "Alien::libtickit",
-   alien_version => "0.12",  # includes 0.4.2a bugfix
 );
 
 $build->create_build_script;
