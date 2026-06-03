--- Build.PL.orig	2026-02-27 16:55:28 UTC
+++ Build.PL
@@ -26,8 +26,6 @@ $build->use_pkgconfig( "tickit",
 
 $build->use_pkgconfig( "tickit",
    atleast_version => "0.4.6",
-   alien         => "Alien::libtickit",
-   alien_version => "0.16",
 );
 
 $build->create_build_script;
