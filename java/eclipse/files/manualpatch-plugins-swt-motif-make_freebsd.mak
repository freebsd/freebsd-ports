--- plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/make_freebsd.mak.orig	Thu Jul 14 20:06:19 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/make_freebsd.mak	Thu Jul 14 20:14:57 2005
@@ -25,26 +25,26 @@
 WS_PREFIX = motif
 SWT_LIB = lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 SWT_OBJS = swt.o callback.o os.o os_structs.o os_custom.o os_stats.o
-SWT_LIBS = -L$(MOTIF_HOME)/lib -lXm -L/usr/lib -L/usr/X11R6/lib \
-	           -rpath . -x -shared -lX11 -lm -lXext -lXt -lXp -ldl -lXinerama -lXtst
+SWT_LIBS = -L$(MOTIF_HOME)/lib -lXm -L$(PREFIX)/lib -L$(X11BASE)/lib \
+	           -rpath . -x -shared -lX11 -lm -lXext -lXt -lXp -lXinerama
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
 
-CFLAGS = -O -s -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DLINUX -DMOTIF  -fpic \
-	-I$(JAVA_HOME)/include -I$(MOTIF_HOME)/include -I/usr/X11R6/include 
+CFLAGS = -O -s -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DFREEBSD -DMOTIF  -fpic -fPIC \
+	-I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd -I$(MOTIF_HOME)/include -I$(X11BASE)/include -I$(PREFIX)/include
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GNOME_PREFIX = swt-gnome
 GNOME_LIB = lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
-GNOME_CFLAGS = -O -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DLINUX -DGTK -I$(JAVA_HOME)/include `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
+GNOME_CFLAGS = -O -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DFREEBSD -DGTK -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd -fpic -fPIC `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
 GNOME_LIBS = -shared -fpic -fPIC `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 AWT_PREFIX = swt-awt
 AWT_LIB = lib$(AWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 AWT_OBJS = swt_awt.o
-AWT_LIBS = -L$(JAVA_HOME)/jre/bin -ljawt -shared
+AWT_LIBS = -L$(JAVA_HOME)/jre/lib/$(MACHINE_ARCH) -ljawt -shared
 
 GTK_PREFIX = swt-gtk
 GTK_LIB = lib$(GTK_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
@@ -77,7 +77,7 @@
 	${SWT_PTR_CFLAGS}
 MOZILLALIBS = -shared -s -Wl,--version-script=mozilla_exports -Bsymbolic ${GECKO_LIBS}
 
-all: make_swt make_awt make_gnome make_gtk
+all: make_swt make_awt $(MAKE_GNOME) make_gtk
 
 make_swt: $(SWT_LIB)
 
