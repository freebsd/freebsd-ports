--- features/org.eclipse.platform.launchers/library/gtk/make_linux.mak	Thu Jun 29 19:22:13 2006
+++ features/org.eclipse.platform.launchers/library/gtk/make_freebsd.mak	Wed Jul 26 18:17:24 2006
@@ -29,7 +29,7 @@
 LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lgdk-x11-2.0
 CFLAGS = -O -s \
 	-fpic \
-	-DLINUX \
+	-DFREEBSD \
 	-DMOZILLA_FIX \
 	-DDEFAULT_OS="\"$(DEFAULT_OS)\"" \
 	-DDEFAULT_OS_ARCH="\"$(DEFAULT_OS_ARCH)\"" \
