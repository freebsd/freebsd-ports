--- Makefile.PL.orig	Thu Aug 14 20:21:46 2003
+++ Makefile.PL	Tue Oct 14 15:09:11 2003
@@ -18,7 +18,7 @@
 
 sub write_makefile {
   WriteMakefile(
-    INSTALLDIRS     => ($] >= 5.008 ? 'perl' : 'site'),
+#    INSTALLDIRS     => ($] >= 5.008 ? 'perl' : 'site'),
     VERSION_FROM    => "lib/List/Util.pm",
     NAME            => "List::Util",
     DISTNAME        => "Scalar-List-Utils",
