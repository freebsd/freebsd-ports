--- features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak.orig	2007-06-26 04:57:08.000000000 +0900
+++ features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak	2007-08-26 18:26:22.000000000 +0900
@@ -23,15 +23,15 @@
 # DEFAULT_WS      - the default value of the "-ws" switch
 # JAVA_HOME      - JAVA_HOME for jni headers      
 #default value for PROGRAM_OUTPUT
-ifeq ($(PROGRAM_OUTPUT),)
+.ifeq ($(PROGRAM_OUTPUT),)
   PROGRAM_OUTPUT=eclipse
-endif
+.endif
 
 PROGRAM_LIBRARY=$(PROGRAM_OUTPUT)_$(LIB_VERSION).so
 
-ifeq ($(DEFAULT_JAVA),)
+.ifeq ($(DEFAULT_JAVA),)
   DEFAULT_JAVA=DEFAULT_JAVA_JNI
-endif
+.endif
 
 # Define the object modules to be compiled and flags.
 CC=gcc
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
