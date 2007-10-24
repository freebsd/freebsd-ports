--- features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak.orig	2007-10-11 15:42:00.000000000 +0900
+++ features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak	2007-10-11 15:57:13.000000000 +0900
@@ -32,7 +32,7 @@
 ifeq ($(DEFAULT_JAVA),)
   DEFAULT_JAVA=DEFAULT_JAVA_JNI
 endif
-
+
 # Define the object modules to be compiled and flags.
 CC=gcc
 MAIN_OBJS = eclipseMain.o
@@ -41,11 +41,11 @@
 
 EXEC = $(PROGRAM_OUTPUT)
 DLL = $(PROGRAM_LIBRARY)
-LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lgdk-x11-2.0 -lpthread -ldl
+LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lgdk-x11-2.0 -lpthread #-ldl
 LFLAGS = -shared -fpic -Wl,--export-dynamic 
 CFLAGS = -O -s -Wall\
 	-fpic \
-	-DLINUX \
+	-DFREEBSD \
 	-DMOZILLA_FIX \
 	-DDEFAULT_OS="\"$(DEFAULT_OS)\"" \
 	-DDEFAULT_OS_ARCH="\"$(DEFAULT_OS_ARCH)\"" \
