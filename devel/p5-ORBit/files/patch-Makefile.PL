--- Makefile.PL.orig	Sun Jul  7 14:24:33 2002
+++ Makefile.PL	Tue May 13 14:40:46 2003
@@ -14,7 +14,7 @@
               server.o
 	      types.o);
 
-$orbit_version = `orbit-config --version`;
+chomp($orbit_version = `orbit-config --version`);
 undef $orbit_version if $?;
 
 if (!defined $orbit_version) {
@@ -41,6 +41,16 @@
 chomp($orbit_libs = `orbit-config --libs client server`);
 #$orbit_libs .= ' -R/opt/ORBit/lib ';
 
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
@@ -50,9 +60,9 @@
     'NAME'	=> 'CORBA::ORBit',
     'VERSION_FROM' => 'ORBit.pm',
     'PREREQ_PM' => { 'Error' => 0.12 },
-    'LIBS'	=> [$orbit_libs." -lIDL"],
+    'LIBS'	=> ["$orbit_libs $idl_libs"],
     'DEFINE'	=> ($] < 5.0045         ? '-DPERL5004_COMPAT ' : ''),
-    'INC'	=> $orbit_cflags,
+    'INC'	=> "$orbit_cflags $idl_cflags",
     'OBJECT'    => join(' ', @OBJECTS),
     'XSOPT'     => '-prototypes',
 #    'XSOPT'     => '-nolinenumbers',
