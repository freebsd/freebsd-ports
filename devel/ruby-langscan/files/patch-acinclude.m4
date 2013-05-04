--- acinclude.m4.orig	2006-01-05 21:51:48.000000000 +0900
+++ acinclude.m4	2013-05-04 17:57:54.000000000 +0900
@@ -41,7 +41,7 @@
   AC_MSG_CHECKING([path to ruby library])
   if test "x$rubydir" = x; then
     changequote(<<, >>)
-    rubydir=`ruby -rrbconfig -e 'puts Config::CONFIG["sitelibdir"]'`
+    rubydir=`ruby -rrbconfig -e 'puts RbConfig::CONFIG["sitelibdir"]'`
     changequote([, ])
   fi
   AC_MSG_RESULT($rubydir)
@@ -57,20 +57,20 @@
   AC_MSG_CHECKING([path to ruby binary library])
   if test "x$rubyarchdir" = x; then
     changequote(<<, >>)
-    rubyarchdir=`ruby -rrbconfig -e 'puts Config::CONFIG["sitearchdir"]'`
+    rubyarchdir=`ruby -rrbconfig -e 'puts RbConfig::CONFIG["sitearchdir"]'`
     changequote([, ])
   fi
   AC_MSG_RESULT($rubyarchdir)
   AC_SUBST(rubyarchdir)
 
   changequote(<<, >>)
-  RUBY_CC="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["CC"]'`"
-  RUBY_LDSHARED="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["LDSHARED"]'`"
-  RUBY_CFLAGS="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["CCDLFLAGS"] + " " + Config::MAKEFILE_CONFIG["CFLAGS"]'`"
-  RUBY_DLEXT="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["DLEXT"]'`"
-  RUBY_DLDFLAGS="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["DLDFLAGS"]'`"
-  RUBY_LIBS="`ruby -rmkmf -e 'puts Config::MAKEFILE_CONFIG["LIBS"]'`"
-  RUBY_HDRHDIR="`ruby -rmkmf -e 'puts Config::CONFIG["archdir"]'`"
+  RUBY_CC="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["CC"]'`"
+  RUBY_LDSHARED="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["LDSHARED"]'`"
+  RUBY_CFLAGS="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["CCDLFLAGS"] + " " + RbConfig::MAKEFILE_CONFIG["CFLAGS"]'` -I\$(CFLAGS)"
+  RUBY_DLEXT="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["DLEXT"]'`"
+  RUBY_DLDFLAGS="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["DLDFLAGS"]'`"
+  RUBY_LIBS="`ruby -rrbconfig -e 'puts RbConfig::MAKEFILE_CONFIG["LIBS"]'`"
+  RUBY_HDRHDIR="`ruby -rrbconfig -e 'puts RbConfig::CONFIG["archdir"]'`"
   RUBY_CPPFLAGS='-I. -I$(RUBY_HDRHDIR)'
   changequote([, ])
 
