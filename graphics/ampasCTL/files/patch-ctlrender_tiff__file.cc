--- ctlrender/tiff_file.cc.orig	2014-06-03 01:11:24 UTC
+++ ctlrender/tiff_file.cc
@@ -53,6 +53,7 @@
 ///////////////////////////////////////////////////////////////////////////
 
 #include "tiff_file.hh"
+#include <cstdlib>
 #include <stdarg.h>
 #include <dpx.hh>
 #if defined(HAVE_LIBTIFF)
@@ -61,7 +62,6 @@
 #include <sys/param.h>
 #include <math.h>
 #include <Iex.h>
-#include <alloca.h>
 
 void tiff_read_multiplane(TIFF *t, float scale, ctl::dpx::fb<float> * pixels);
 void tiff_read_interleaved(TIFF *t, float scale, ctl::dpx::fb<float> * pixels);
