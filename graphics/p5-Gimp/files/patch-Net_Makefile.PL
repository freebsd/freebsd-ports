--- Net/Makefile.PL.orig	Fri Dec 22 07:12:42 2000
+++ Net/Makefile.PL	Fri Dec 22 07:20:48 2000
@@ -15,7 +15,7 @@
     'NAME'	=> 'Gimp::Net',
     'VERSION_FROM' => '../Gimp.pm',
     #'INC'	=> "$INC1 $CPPFLAGS $pdl_inc $cfg{GLIB_CFLAGS} $CFLAGS",
-    'INC'	=> "$INC1 $CPPFLAGS $pdl_inc $CFLAGS",
+    'INC'	=> "$INC1 $CPPFLAGS $pdl_inc $CFLAGS -I/usr/local/include",
     'DEFINE'	=> "$DEFINE1 $DEFS",
     'TYPEMAPS'	=> ["$topdir/typemap",@pdl_typemaps],
     #dynamic_lib	=> { OTHERLDFLAGS => "$LDFLAGS $LIBS $cfg{GLIB_LIBS}" },
