--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig	Mon Oct  9 16:06:20 2006
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	Mon Oct  9 16:27:59 2006
@@ -48,7 +48,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(X11BASE)/lib $(XLIB64) -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -61,7 +61,7 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(X11BASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
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
