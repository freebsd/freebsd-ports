--- Makefile.PL.orig	2007-05-27 15:43:06 UTC
+++ Makefile.PL
@@ -6,8 +6,8 @@ all_from('lib/DateTime/Event/Lunar.pm');
 
 requires 'DateTime';
 requires 'DateTime::Set';
-requires 'DateTime::Util::Astro' => 0.10;
+requires 'DateTime::Astro' => 1.00;
 requires 'Math::Round';
 
 auto_install;
-WriteAll;
\ No newline at end of file
+WriteAll;
