--- subversion/bindings/swig/perl/native/Base.pm.orig	2004-10-20 10:46:59.000000000 +0400
+++ subversion/bindings/swig/perl/native/Base.pm	2004-11-05 11:43:35.578125000 +0300
@@ -60,6 +60,7 @@
 package SVN::_$pkg;
 require DynaLoader;
 bootstrap SVN::_$pkg;
+sub dl_load_flags { 0x01 }
 1;
     ' or die $@;
     };
