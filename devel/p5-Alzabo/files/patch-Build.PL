--- Build.PL.orig	Mon Mar 13 12:58:21 2006
+++ Build.PL	Tue May 30 21:27:00 2006
@@ -18,6 +18,7 @@
             'automated' => \$opts{automated},
             'help'   => \$opts{help},
           );
+$opts{automated} = 1;
 
 if ( $opts{help} )
 {
