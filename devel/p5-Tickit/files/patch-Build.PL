--- Build.PL.orig	2022-08-26 14:37:31 UTC
+++ Build.PL
@@ -28,8 +28,6 @@ my $build = Module::Build::Using::PkgConfig->new(
 
 $build->use_pkgconfig( "tickit",
    atleast_version => "0.4.3",
-   alien         => "Alien::libtickit",
-   alien_version => "0.13",  # includes 0.4.2a bugfix
 );
 
 $build->create_build_script;
