--- features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak.orig	2008-08-02 15:47:34.000000000 -0400
+++ features/org.eclipse.equinox.executable/library/gtk/make_freebsd.mak	2008-08-02 15:47:42.000000000 -0400
@@ -42,12 +42,12 @@
 EXEC = $(PROGRAM_OUTPUT)
 DLL = $(PROGRAM_LIBRARY)
 #LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lgdk-x11-2.0 -lpthread -ldl
-LIBS = -lpthread -ldl
+LIBS = -lpthread
 GTK_LIBS = -DGTK_LIB="\"libgtk-x11-2.0.so.0\"" -DGDK_LIB="\"libgdk-x11-2.0.so.0\"" -DPIXBUF_LIB="\"libgdk_pixbuf-2.0.so.0\"" -DGOBJ_LIB="\"libgobject-2.0.so.0\""
 LFLAGS = -shared -fpic -Wl,--export-dynamic 
 CFLAGS = -g -s -Wall\
 	-fpic \
-	-DLINUX \
+	-DFREEBSD \
 	-DMOZILLA_FIX \
 	-DDEFAULT_OS="\"$(DEFAULT_OS)\"" \
 	-DDEFAULT_OS_ARCH="\"$(DEFAULT_OS_ARCH)\"" \
