--- Makefile.PL.orig	2003-08-13 14:16:29 UTC
+++ Makefile.PL
@@ -4,8 +4,7 @@ use ExtUtils::MakeMaker;
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
