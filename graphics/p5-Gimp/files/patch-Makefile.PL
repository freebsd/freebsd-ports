--- Makefile.PL.orig	Sat Dec  1 07:02:29 2001
+++ Makefile.PL	Thu Apr 11 17:52:04 2002
@@ -333,7 +333,7 @@
     		    'Gimp/Config.pm'	=> '$(INST_LIBDIR)/Gimp/Config.pm',
     		   },
     'LDFROM'	=> expand("\$(OBJECT) $LIBS $INTLLIBS"),
-    'INC'	=> "$INC1 $GIMP_INC_NOUI $CPPFLAGS $CFLAGS",
+    'INC'	=> "$INC1 $GIMP_INC_NOUI $CPPFLAGS $CFLAGS -I/usr/local/include",
     'DEFINE'	=> "$DEFINE1 $DEFS",
     'EXE_FILES'	=> \@EXE_FILES,
     'macro'	=> \%cfg,
