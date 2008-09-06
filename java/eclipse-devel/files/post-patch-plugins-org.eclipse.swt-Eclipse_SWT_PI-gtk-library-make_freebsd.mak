--- gtk/library/make_freebsd.mak.orig	2008-08-02 21:59:10.233269779 -0400
+++ gtk/library/make_freebsd.mak	2008-08-02 21:59:50.313515173 -0400
@@ -46,7 +46,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(LOCALBASE)/lib -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -59,7 +59,7 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(LOCALBASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
@@ -74,11 +74,11 @@
 	-Wno-non-virtual-dtor \
 	-fPIC \
 	-I. \
+	-I$(LOCALBASE)/include \
 	-I$(JAVA_HOME)/include \
 	-I$(JAVA_HOME)/include/freebsd \
 	${SWT_PTR_CFLAGS}
 MOZILLALIBS = -shared -Wl,--version-script=mozilla_exports -Bsymbolic
-MOZILLAEXCLUDES = -DNO_XPCOMGlueShutdown -DNO_XPCOMGlueStartup
 	
 SWT_OBJECTS = swt.o c.o c_stats.o callback.o
 CDE_OBJECTS = swt.o cde.o cde_structs.o cde_stats.o
@@ -95,20 +95,21 @@
 CFLAGS = -O -Wall \
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
-		-DLINUX -DGTK \
+		-DFREEBSD -DGTK \
+		-I$(LOCALBASE)/include \
 		-I$(JAVA_HOME)/include \
 		-I$(JAVA_HOME)/include/freebsd \
 		-fPIC \
 		${SWT_PTR_CFLAGS}
 LIBS = -shared -fPIC
 
-ifndef NO_STRIP
-	AWT_LIBS := $(AWT_LIBS) -s
-	MOZILLALIBS := $(MOZILLALIBS) -s
-	LIBS := $(LIBS) -s
-endif
+.ifndef NO_STRIP
+AWT_LIBS := $(AWT_LIBS) -s
+MOZILLALIBS := $(MOZILLALIBS) -s
+LIBS := $(LIBS) -s
+.endif
 
-all: make_swt make_atk make_gnome make_glx
+all: make_swt make_atk $(MAKE_GNOME) make_glx $(MAKE_MOZILLA) $(MAKE_CAIRO) $(MAKE_AWT)
 
 #
 # SWT libs
@@ -167,6 +168,9 @@
 $(AWT_LIB): $(AWT_OBJECTS)
 	$(CC) $(AWT_LIBS) -o $(AWT_LIB) $(AWT_OBJECTS)
 
+swt_awt.o: swt_awt.c
+	$(CC) $(CFLAGS) -c swt_awt.c
+
 #
 # Atk lib
 #
