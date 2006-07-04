--- Makefile.PL.orig	Mon Apr 17 15:43:46 2006
+++ Makefile.PL	Tue Jul  4 15:55:49 2006
@@ -14,13 +14,6 @@
     chomp($libpath);
     our $incpath = $libpath . "/include/taglib";
     $libpath .= -d $libpath. "/lib64" ? "/lib64" : "/lib";
-    my ($lib) = glob($libpath . "/libtag.so.1.4.*");
-    if (defined $lib) {
-        print STDOUT "got $lib, good, go on\n";
-    } else {
-        Carp::croak("version 1.4.* not found,". 
-                    "please install firstly\n");
-    }
 }
 
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
@@ -37,9 +30,9 @@
     LD                => 'g++',
     LDDLFLAGS         => "-shared -L${libpath}",
     XSOPT             => '-C++ -hiertype',
-    LIBS              => ['-ltag'], # e.g., '-lm'
+    LIBS              => ['-ltag -liconv'],
     DEFINE            => $^O eq 'freebsd' ? '-D_BSD_ICONV -DNO_DOXYGEN' : '-DNO_DOXYGEN', # e.g., '-DHAVE_SOMETHING'
-    INC               => "-I${incpath} -I/usr/include -I./include ", # e.g., '-I. -I/usr/include/other'
+    INC               => "-I${incpath} -I/usr/include -I./include -I\$(PREFIX)/include",
 	# Un-comment this if you add C files to link with later:
     # OBJECT            => '$(O_FILES)', # link all the C files too
 );
