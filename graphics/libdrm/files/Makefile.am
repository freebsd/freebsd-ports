--- Makefile.am.orig	2016-12-13 03:45:20.000000000 +0100
+++ Makefile.am	2017-01-30 14:02:04.821902000 +0100
@@ -115,9 +115,9 @@
 libdrm_la_LTLIBRARIES = libdrm.la
 libdrm_ladir = $(libdir)
 libdrm_la_LDFLAGS = -version-number 2:4:0 -no-undefined
-libdrm_la_LIBADD = @CLOCK_LIB@ -lm
+libdrm_la_LIBADD = @CLOCK_LIB@ -lm @LIBDEVQ_LIBS@
 
-libdrm_la_CPPFLAGS = -I$(top_srcdir)/include/drm
+libdrm_la_CPPFLAGS = -I$(top_srcdir)/include/drm @LIBDEVQ_CFLAGS@
 AM_CFLAGS = \
 	$(WARN_CFLAGS) \
 	$(VALGRIND_CFLAGS)
