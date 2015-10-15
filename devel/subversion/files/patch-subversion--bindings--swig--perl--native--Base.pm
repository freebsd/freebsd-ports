--- subversion/bindings/swig/perl/native/Base.pm.orig	2012-12-02 18:57:14.000000000 +0400
+++ subversion/bindings/swig/perl/native/Base.pm	2015-10-15 01:30:46.451308089 +0300
@@ -60,6 +60,7 @@
 package SVN::_$pkg;
 require DynaLoader;
 bootstrap SVN::_$pkg;
+sub dl_load_flags { 0x01 }
 1;
     ' or die $@;
     };
