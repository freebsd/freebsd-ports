--- Makefile.PL	2015-02-23 09:23:19.000000000 -0800
+++ Makefile.PL	2015-02-23 09:24:02.000000000 -0800
@@ -144,6 +144,7 @@
 
 # Look for libgif
 for my $incdir ( $gif_inc, @check ) {
+    last;
     if ( $incdir && -e catfile($incdir, 'gif_lib.h') ) {
         $GIF = 1;
         $gif_inc = $incdir;
