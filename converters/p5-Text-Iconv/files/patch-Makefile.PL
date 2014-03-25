--- Makefile.PL.orig	2007-10-17 16:06:22.000000000 +0200
+++ Makefile.PL	2014-03-24 21:28:37.147481295 +0100
@@ -90,6 +90,7 @@
 		AUTHOR        => 'Michael Piotrowski <mxp@dynalabs.de>') : ()),
 	      'LIBS'              => $config{LIBS},
 	      'DEFINE'            => "@DEFINE",
+              'CCFLAGS'           => $config{ccflags},
 	      'INC'               => $config{INC},
 	      'dist'              => {COMPRESS => 'gzip', SUFFIX => 'gz'},
 	     );
@@ -119,12 +120,12 @@
    {
       # It is admittedly a bit simplistic to simply concatenate all
       # flags, but it seems to work in most cases.
-      $compile = join ' ', $Config{cc}, $incs, $Config{ccflags},
+      $compile = join ' ', $Config{cc}, $incs, $config{ccflags},
 	  $Config{ldflags}, $libs;
    }
    else
    {
-      $compile = join ' ', $Config{cc}, $incs, $Config{ccflags}, $libs;
+      $compile = join ' ', $Config{cc}, $incs, $config{ccflags}, $libs;
    }
 
    if (exists $config{verbose})
