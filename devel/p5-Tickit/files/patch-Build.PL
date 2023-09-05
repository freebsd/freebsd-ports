--- Build.PL.orig	2023-09-04 17:08:20 UTC
+++ Build.PL
@@ -26,8 +26,6 @@ my $build = Module::Build::Using::PkgConfig->new(
 
 $build->use_pkgconfig( "tickit",
    atleast_version => "0.4.4",
-   alien         => "Alien::libtickit",
-   alien_version => "0.14",
 );
 
 $build->create_build_script;
