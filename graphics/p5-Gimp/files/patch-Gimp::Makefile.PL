--- Gimp/Makefile.PL.orig	Thu Apr 11 17:54:39 2002
+++ Gimp/Makefile.PL	Thu Apr 11 17:54:56 2002
@@ -33,7 +33,7 @@
 WriteMakefile(
     'NAME'	=> 'Gimp::Lib',
     'VERSION_FROM' => '../Gimp.pm',
-    'INC'	=> "$INC1 $GIMP_INC_NOUI $CPPFLAGS $pdl_inc $CFLAGS",
+    'INC'	=> "$INC1 $GIMP_INC_NOUI $CPPFLAGS $pdl_inc $CFLAGS -I/usr/local/include",
     'DEFINE'	=> "$DEFINE1 $DEFS",
     'macro'	=> { libdir => $libdir, exec_prefix => $exec_prefix, prefix => $prefix },
     'TYPEMAPS'	=> ["$topdir/typemap",@pdl_typemaps],
