
$FreeBSD$

--- Makefile.PL.orig	Mon Oct 23 08:53:08 2000
+++ Makefile.PL	Wed Jul 31 16:09:47 2002
@@ -4,8 +4,7 @@
 WriteMakefile(
     'NAME'	=> 'Ogg::Vorbis',
     'VERSION_FROM' => 'Vorbis.pm',
-    'LIBS'	=> ['-logg -lvorbis -lvorbisfile'],
+    'LIBS'	=> ['-L%%PREFIX%%/lib -logg -lvorbis -lvorbisfile'],
     'DEFINE'	=> '',
-    'INC'	=> '-I/usr/local/include/vorbis',
-    'EXE_FILES' => ['pogg'],
+    'INC'	=> '-I%%PREFIX%%/include',
 );
