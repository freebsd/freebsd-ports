--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig	Thu Dec 14 18:01:12 2006
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	Thu Dec 14 18:03:00 2006
@@ -48,7 +48,7 @@
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GTKCFLAGS = `pkg-config --cflags gtk+-2.0`
-GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L/usr/X11R6/lib $(XLIB64) -lXtst
+GTKLIBS = `pkg-config --libs-only-L gtk+-2.0 gthread-2.0` -lgtk-x11-2.0 -lgthread-2.0 -L$(LOCALBASE)/lib $(XLIB64) -lXtst
 
 CDE_LIBS = -L$(CDE_HOME)/lib -R$(CDE_HOME)/lib -lXt -lX11 -lDtSvc
 
@@ -61,7 +61,7 @@
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 GLXCFLAGS = 
-GLXLIBS = -shared -fPIC -L/usr/X11R6/lib -lGL -lGLU -lm
+GLXLIBS = -shared -fPIC -L$(LOCALBASE)/lib -lGL -lGLU -lm
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
@@ -79,6 +79,10 @@
 	-I. \
 	-I$(JAVA_HOME)/include \
 	-I$(JAVA_HOME)/include/freebsd \
+	-I$(LOCALBASE)/include/%%GECKO%% \
+	-I$(LOCALBASE)/include/%%GECKO%%/profdirserviceprovider \
+	-I$(LOCALBASE)/include/%%GECKO%%/string \
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
+                -I$(LOCALBASE)/include \
 		-fPIC \
 		${SWT_PTR_CFLAGS}
 LIBS = -shared -fPIC -s
 
 
-all: make_swt make_atk make_gnome make_glx
+all: make_swt make_atk $(MAKE_GNOME) make_glx $(MAKE_MOZILLA) $(MAKE_CAIRO)
 
 #
 # SWT libs
@@ -202,7 +207,7 @@
 #
 # Mozilla lib
 #
-make_mozilla:$(MOZILLA_LIB) $(PROFILE14_LIB) $(PROFILE17_LIB) $(PROFILE18_LIB)
+make_mozilla:$(MOZILLA_LIB)
 
 $(MOZILLA_LIB): $(MOZILLA_OBJECTS)
 	$(CXX) -o $(MOZILLA_LIB) $(MOZILLA_OBJECTS) $(MOZILLALIBS) ${GECKO_LIBS}
@@ -220,22 +225,22 @@
 	$(CXX) $(MOZILLACFLAGS) ${GECKO_INCLUDES} -c xpcom_stats.cpp	
 
 $(PROFILE14_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE14_OBJECTS) $(MOZILLACFLAGS) ${PROFILE14_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE14_OBJECTS) $(MOZILLACFLAGS) ${PROFILE14_INCLUDES} ${GECKO_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE17_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE17_OBJECTS) $(MOZILLACFLAGS) ${PROFILE17_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE17_OBJECTS) $(MOZILLACFLAGS) ${PROFILE17_INCLUDES} ${GECKO_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE18_OBJECTS): xpcom_profile.cpp
-	$(CXX) -o $(PROFILE18_OBJECTS) $(MOZILLACFLAGS) ${PROFILE18_INCLUDES} -c xpcom_profile.cpp	
+	$(CXX) -o $(PROFILE18_OBJECTS) $(MOZILLACFLAGS) ${PROFILE18_INCLUDES} ${GECKO_INCLUDES} -c xpcom_profile.cpp	
 
 $(PROFILE14_LIB): $(PROFILE14_OBJECTS)
-	$(CXX) -o $(PROFILE14_LIB) $(PROFILE14_OBJECTS) $(MOZILLALIBS) ${PROFILE14_LIBS}
+	$(CXX) -o $(PROFILE14_LIB) $(PROFILE14_OBJECTS) $(MOZILLALIBS) ${PROFILE14_LIBS} ${GECKO_LIBS}
 
 $(PROFILE17_LIB): $(PROFILE17_OBJECTS)
-	$(CXX) -o $(PROFILE17_LIB) $(PROFILE17_OBJECTS) $(MOZILLALIBS) ${PROFILE17_LIBS}
+	$(CXX) -o $(PROFILE17_LIB) $(PROFILE17_OBJECTS) $(MOZILLALIBS) ${PROFILE17_LIBS} ${GECKO_LIBS}
 
 $(PROFILE18_LIB): $(PROFILE18_OBJECTS)
-	$(CXX) -o $(PROFILE18_LIB) $(PROFILE18_OBJECTS) $(MOZILLALIBS) ${PROFILE18_LIBS}
+	$(CXX) -o $(PROFILE18_LIB) $(PROFILE18_OBJECTS) $(MOZILLALIBS) ${PROFILE18_LIBS} ${GECKO_LIBS}
 
 #
 # GLX lib
