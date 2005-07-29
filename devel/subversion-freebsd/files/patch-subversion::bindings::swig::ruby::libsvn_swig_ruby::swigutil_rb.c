--- subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c.orig	Tue Mar 22 23:42:12 2005
+++ subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c	Mon Jul  4 02:40:49 2005
@@ -1,10 +1,16 @@
-#include "swigutil_rb.h"
 #include <st.h>
 
-#include <swigrun.swg>
+#if SVN_SWIG_VERSION >= 103024
+#if SVN_SWIG_VERSION >= 103025
+#include <swiglabels.swg>
+#endif
 #include <ruby/rubyhead.swg>
-#include <common.swg>
+#include <swigrun.swg>
 #include <ruby/rubydef.swg>
+#include <runtime.swg>
+#endif
+
+#include "swigutil_rb.h"
 
 static VALUE mSvn = Qnil;
 static VALUE mSvnCore = Qnil;
