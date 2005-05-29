--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig	Sat May 14 19:50:23 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	Sat May 14 21:24:34 2005
@@ -78,15 +78,16 @@
 CFLAGS = -O -Wall \
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
-		-DLINUX -DGTK \
+		-DFREEBSD -DGTK \
 		-I$(JAVA_HOME)/include \
 		-I$(JAVA_HOME)/include/freebsd \
-		-fpic \
+		-I$(X11BASE)/include \
+		-fpic -fPIC \
 		${SWT_PTR_CFLAGS}
-LIBS = -shared -fpic -s
+LIBS = -shared -fpic -fPIC -s
 
 
-all: make_swt make_atk make_gnome make_awt
+all: make_swt make_atk $(MAKE_GNOME) make_awt
 
 #
 # SWT libs
