--- Makefile.PL.orig	Tue Apr  6 18:23:32 2004
+++ Makefile.PL	Tue Apr  6 18:23:44 2004
@@ -13,6 +13,6 @@
 	      'NAME' => 'Search::Namazu',
 	      'VERSION_FROM' => 'Namazu.pm',
 	      'INC' => $cflags,
-	      'LIBS' => $libs,
+	      'LIBS' => "$libs -lintl",
 	      'clean' => {'FILES' => "t/index"}
 );
