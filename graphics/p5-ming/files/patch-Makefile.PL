--- Makefile.PL.orig	Sat Aug 18 02:05:50 2001
+++ Makefile.PL	Tue Sep 18 15:09:21 2001
@@ -37,14 +37,14 @@
 WriteMakefile(
     'NAME'	   => 'SWF',
     'VERSION_FROM' => 'SWF.pm', # finds $VERSION
-    'LIBS'	   => [''],   # e.g., '-lm' 
+    'LIBS'	   => ["-L$ENV{LOCALBASE}/lib -lming"],   # e.g., '-lm' 
     'DEFINE'	   => '',     # e.g., '-DHAVE_SOMETHING' 
     'INC'	   => '',     # e.g., '-I/usr/include/other'
-    'MYEXTLIB'     => $MING_DIR . '/libming.a',
+#    'MYEXTLIB'     => $MING_DIR . '/libming.a',
 );
 
 sub ming_is_compiled{
-    return undef unless (-e "$MING_DIR/libming.a");
+#    return undef unless (-e "$MING_DIR/libming.a");
     return 1;
 }
 
