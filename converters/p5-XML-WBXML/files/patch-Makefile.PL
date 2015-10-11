--- Makefile.PL.orig	2015-05-21 10:43:29 UTC
+++ Makefile.PL
@@ -10,9 +10,9 @@ WriteMakefile(
     ABSTRACT_FROM => 'lib/XML/WBXML.pm',                                                                            # retrieve abstract from module
     LICENSE       => 'perl_5',
     PREREQ_PM     => {},                                                                                         # e.g., Module::Name => 1.1
-    LIBS          => ['-lwbxml2'],                                                                               # e.g., '-lm'
+    LIBS          => ['-L%%LOCALBASE%%/lib -lwbxml2'],                                                                               # e.g., '-lm'
     DEFINE        => '',                                                                                         # e.g., '-DHAVE_SOMETHING'
-    INC           => '-I.',                                                                                      # e.g., '-I. -I/usr/include/other'
+    INC           => '-I. -I%%LOCALBASE%%/include -I/usr/local/include/libwbxml-1.0/wbxml',                      # e.g., '-I. -I/usr/include/other'
 
     # Un-comment this if you add C files to link with later:
     # OBJECT            => '$(O_FILES)', # link all the C files too
