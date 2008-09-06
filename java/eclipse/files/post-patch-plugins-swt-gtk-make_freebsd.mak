--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig	2007-10-08 00:19:29.000000000 +0900
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	2007-10-08 00:36:34.000000000 +0900
@@ -46,7 +46,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(LOCALBASE)/lib $(XLIB64) -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -59,10 +59,10 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(LOCALBASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
-#NATIVE_STATS = -DNATIVE_STATS
+NATIVE_STATS = -DNATIVE_STATS
 
 MOZILLACFLAGS = -O \
 	-DSWT_VERSION=$(SWT_VERSION) \
@@ -74,11 +74,15 @@
 	-Wno-non-virtual-dtor \
 	-fPIC \
 	-I. \
+	-I$(LOCALBASE)/include \
 	-I$(JAVA_HOME)/include \
 	-I$(JAVA_HOME)/include/freebsd \
+	-I$(LOCALBASE)/include/xulrunner \
+	-I$(LOCALBASE)/include/xulrunner/profdirserviceprovider \
+	-I$(LOCALBASE)/include/xulrunner/string \
+	-I$(LOCALBASE)/include/nspr \
 	${SWT_PTR_CFLAGS}
 MOZILLALIBS = -shared -Wl,--version-script=mozilla_exports -Bsymbolic
-MOZILLAEXCLUDES = -DNO_XPCOMGlueShutdown -DNO_XPCOMGlueStartup
 	
 SWT_OBJECTS = swt.o c.o c_stats.o callback.o
 CDE_OBJECTS = swt.o cde.o cde_structs.o cde_stats.o
@@ -88,27 +92,28 @@
 ATK_OBJECTS = swt.o atk.o atk_structs.o atk_custom.o atk_stats.o
 GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
 MOZILLA_OBJECTS = swt.o xpcom.o xpcom_custom.o xpcom_structs.o xpcom_stats.o
-XULRUNNER_OBJECTS = swt.o xpcomxul.o xpcomxul_custom.o xpcomxul_structs.o xpcomxul_stats.o
+XULRUNNER_OBJECTS = swt.o xpcomxul.o xpcomxul_custom.o xpcomxul_structs.o xpcomxul_stats.o xpcomxulglue.o xpcomxulglue_stats.o
 XPCOMINIT_OBJECTS = swt.o xpcominit.o xpcominit_structs.o xpcominit_stats.o
 GLX_OBJECTS = swt.o glx.o glx_structs.o glx_stats.o
 
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
+all: make_swt make_atk $(MAKE_GNOME) make_glx $(MAKE_MOZILLA) $(MAKE_CAIRO)
 
 #
 # SWT libs
@@ -210,7 +215,7 @@
 	$(CXX) -o $(MOZILLA_LIB) $(MOZILLA_OBJECTS) $(MOZILLALIBS) ${MOZILLA_LIBS}
 
 xpcom.o: xpcom.cpp
-	$(CXX) $(MOZILLACFLAGS) $(MOZILLAEXCLUDES) ${MOZILLA_INCLUDES} -c xpcom.cpp
+	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom.cpp
 
 xpcom_structs.o: xpcom_structs.cpp
 	$(CXX) $(MOZILLACFLAGS) ${MOZILLA_INCLUDES} -c xpcom_structs.cpp
@@ -241,6 +246,12 @@
 xpcomxul_stats.o: xpcom_stats.cpp
 	$(CXX) -o xpcomxul_stats.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcom_stats.cpp
 
+xpcomxulglue.o: xpcomglue.cpp
+	$(CXX) -o xpcomxulglue.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcomglue.cpp
+
+xpcomxulglue_stats.o: xpcomglue_stats.cpp
+	$(CXX) -o xpcomxulglue_stats.o $(MOZILLACFLAGS) ${XULRUNNER_INCLUDES} -c xpcomglue_stats.cpp
+
 #
 # XPCOMInit lib
 #
