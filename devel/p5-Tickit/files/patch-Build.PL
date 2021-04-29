--- Build.PL.orig	2020-05-25 11:01:56 UTC
+++ Build.PL
@@ -27,8 +27,6 @@ my $build = Module::Build::Using::PkgConfig->new(
 
 $build->use_pkgconfig( "tickit",
    atleast_version => "0.4.0",
-   alien         => "Alien::libtickit",
-   alien_version => "0.09",
 );
 
 $build->create_build_script;
