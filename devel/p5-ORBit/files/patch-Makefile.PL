--- Makefile.PL.orig	Wed Oct 25 15:27:13 2000
+++ Makefile.PL	Tue Oct 15 20:38:18 2002
@@ -14,9 +14,9 @@
               server.o
 	      types.o);
 
-$orbit_cflags = `orbit-config --cflags client server`;
+chomp($orbit_cflags = `orbit-config --cflags client server`);
 undef $orbit_cflags if $?;
-$orbit_libs = `orbit-config --libs client server`;
+chomp($orbit_libs = `orbit-config --libs client server`);
 undef $orbit_libs if $?;
 
 if (!defined $orbit_libs) {
@@ -24,6 +24,16 @@
     exit 1;
 }
 
+chomp($idl_cflags = `libIDL-config --cflags`);
+undef $idl_cflags if $?;
+chomp($idl_libs = `libIDL-config --libs`);
+undef $idl_libs if $?;
+
+if (!defined $idl_libs) {
+    print STDERR "libIDL-config not found\n";
+    exit 1;
+}
+
 if ($] < 5.0045) {
     print STDERR "Using compatibility macros/routines for Perl 5.004\n";
     push @OBJECTS,'constsub.o';
@@ -32,13 +42,13 @@
 WriteMakefile(
     'NAME'	=> 'CORBA::ORBit',
     'VERSION_FROM' => 'ORBit.pm',
-    'LIBS'	=> [$orbit_libs." -lIDL"],
+    'LIBS'	=> ["$orbit_libs $idl_libs"],
     'DEFINE'	=> 
         ($] < 5.0045         ? '-DPERL5004_COMPAT ' : ''),
-    'INC'	=> $orbit_cflags,
+    'INC'	=> "$orbit_cflags $idl_cflags",
     'OBJECT'    => join(" ", @OBJECTS),
 #    'XSOPT'     => '-nolinenumbers',
-    'OPTIMIZE'  => '-g -Wall',
+    'OPTIMIZE'  => '-Wall',
 #    'OPTIMIZE'  => '-O2 -Wall',
     'MAP_TARGET' => 'orbitperl',
 #    'MAKEAPERL' => 1,
