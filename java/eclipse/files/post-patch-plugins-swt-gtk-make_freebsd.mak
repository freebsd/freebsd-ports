--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig	Mon Oct  9 16:06:20 2006
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	Mon Oct  9 16:27:59 2006
@@ -79,6 +79,10 @@
 	-I. \
 	-I$(JAVA_HOME)/include \
 	-I$(JAVA_HOME)/include/freebsd \
+	-I$(LOCALBASE)/include/mozilla \
+	-I$(LOCALBASE)/include/mozilla/profdirserviceprovider \
+	-I$(LOCALBASE)/include/mozilla/string \
+	-I$(LOCALBASE)/include/nspr \
 	${SWT_PTR_CFLAGS}
 MOZILLALIBS = -shared -s -Wl,--version-script=mozilla_exports -Bsymbolic
 	
@@ -98,15 +102,16 @@
 CFLAGS = -O -Wall \
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
-		-DLINUX -DGTK \
+		-DFREEBSD -DGTK \
 		-I$(JAVA_HOME)/include \
 		-I$(JAVA_HOME)/include/freebsd \
+                -I$(X11BASE)/include \
 		-fPIC \
 		${SWT_PTR_CFLAGS}
 LIBS = -shared -fPIC -s
 
 
-all: make_swt make_atk make_gnome make_glx
+all: make_swt make_atk $(MAKE_GNOME) make_glx $(MAKE_MOZILLA) $(MAKE_CAIRO)
 
 #
 # SWT libs
