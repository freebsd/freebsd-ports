--- Makefile.am.orig	2016-06-23 14:29:40.575882000 +0200
+++ Makefile.am	2016-06-23 14:38:48.752016000 +0200
@@ -108,9 +108,9 @@
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
