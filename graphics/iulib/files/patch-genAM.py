--- ./genAM.py.orig	2009-06-10 07:32:20.000000000 +0900
+++ ./genAM.py	2009-06-11 18:24:46.000000000 +0900
@@ -25,12 +25,12 @@
 # Primary Repository: http://ocropus.googlecode.com/svn/trunk/
 # Web Sites: www.iupr.org, www.dfki.de
 
-AM_CPPFLAGS = -I$(srcdir)/colib -I$(srcdir)/imgio -I$(srcdir)/imglib
+AM_CPPFLAGS = -I$(srcdir)/colib -I$(srcdir)/imgio -I$(srcdir)/imglib -I$(srcdir)/imgbits -I$(srcdir)/utils -I$(srcdir)/vidio
 
 includedir = ${prefix}/include/iulib
 colibdir = ${prefix}/include/colib
 
-lib_LIBRARIES = libiulib.a
+lib_LTLIBRARIES = libiulib.la
 """
 
 dirs = """
@@ -39,7 +39,7 @@
     imgbits
 """.split()
 
-print "libiulib_a_SOURCES = ",
+print "libiulib_la_SOURCES = ",
 for d in dirs:
     print '\\'
     for cc in glob.glob(d + "/*.cc"):
@@ -82,35 +82,23 @@
 print """
 # conditionals
 if have_sdl
-    libiulib_a_SOURCES += $(srcdir)/utils/dgraphics.cc
-    libiulib_a_SOURCES += $(srcdir)/utils/SDL_lines.cc
+    libiulib_la_SOURCES += $(srcdir)/utils/dgraphics.cc
+    libiulib_la_SOURCES += $(srcdir)/utils/SDL_lines.cc
     include_HEADERS += $(srcdir)/utils/SDL_lines.h
 else
-    libiulib_a_SOURCES += $(srcdir)/utils/dgraphics_nosdl.cc
+    libiulib_la_SOURCES += $(srcdir)/utils/dgraphics_nosdl.cc
 endif
 
 if have_vidio
-    libiulib_a_SOURCES += $(srcdir)/vidio/vidio.cc
+    libiulib_la_SOURCES += $(srcdir)/vidio/vidio.cc
 endif
 
 # We install it always because iulib.h always includes it.
 include_HEADERS += $(srcdir)/vidio/vidio.h
 
 if have_v4l2
-    libiulib_a_SOURCES += $(srcdir)/vidio/v4l2cap.cc
+    libiulib_la_SOURCES += $(srcdir)/vidio/v4l2cap.cc
 endif
-
-# make installation of colib a separate target
-
-install-colib:
-	install -d $(colibdir)
-	install $(colib_HEADERS) $(colibdir)
-
-install: all install-colib
-	install -d $(includedir)
-	install -d $(libdir)
-	install $(include_HEADERS) $(includedir)
-	install $(lib_LIBRARIES) $(libdir)
 """
 
 print
