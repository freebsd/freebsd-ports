--- plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/make_linux.mak.orig	Fri Apr  1 13:57:23 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/motif/library/make_linux.mak	Sat Apr  9 14:20:28 2005
@@ -26,32 +26,32 @@
 WS_PREFIX = motif
 SWT_LIB = lib$(SWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 SWT_OBJS = swt.o callback.o os.o os_structs.o os_custom.o os_stats.o
-SWT_LIBS = -L$(MOTIF_HOME)/lib -lXm -L/usr/lib -L/usr/X11R6/lib \
-	           -rpath . -x -shared -lX11 -lm -lXext -lXt -lXp -ldl -lXinerama -lXtst
+SWT_LIBS = -L$(MOTIF_HOME)/lib -lXm -L$(PREFIX)/lib -L$(X11BASE)/lib \
+	           -rpath . -x -shared -lX11 -lm -lXext -lXt -lXp -lXinerama
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
 
-CFLAGS = -O -s -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DLINUX -DMOTIF  -fpic -I./ \
-	-I$(JAVA_HOME)/include -I$(MOTIF_HOME)/include -I/usr/X11R6/include 
+CFLAGS = -O -g -s -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DFREEBSD -DMOTIF  -fpic -fPIC -I./ \
+	-I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd -I$(MOTIF_HOME)/include -I$(X11BASE)/include  -I$(PREFIX)/include 
 
 # Do not use pkg-config to get libs because it includes unnecessary dependencies (i.e. pangoxft-1.0)
 GNOME_PREFIX = swt-gnome
 GNOME_LIB = lib$(GNOME_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
-GNOME_CFLAGS = -O -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DLINUX -DGTK -I$(JAVA_HOME)/include `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
+GNOME_CFLAGS = -O -g -Wall -DSWT_VERSION=$(SWT_VERSION) $(NATIVE_STATS) -DFREEBSD -DGTK -fpic -fPIC -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
 GNOME_LIBS = -shared -fpic -fPIC `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
 KDE_PREFIX = swt-kde
 KDE_LIB = lib$(KDE_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 KDE_OBJS = swt.o kde.o kde_stats.o
-KDE_LIBS = -L/usr/lib  -L$(QT_HOME)/lib -shared  -lkdecore -lqt -lkparts
-KDE_CFLAGS = -fno-rtti -c -O -I/usr/include/kde -I$(QT_HOME)/include -I$(JAVA_HOME)/include
+KDE_LIBS = -L$(PREFIX)/lib  -L$(QT_HOME)/lib -shared  -lkdecore -lqt -lkparts
+KDE_CFLAGS = -fno-rtti -c -O -I/usr/include/kde -I$(QT_HOME)/include -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd 
 
 AWT_PREFIX = swt-awt
 AWT_LIB = lib$(AWT_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
 AWT_OBJS = swt_awt.o
-AWT_LIBS = -L$(JAVA_HOME)/jre/bin -ljawt -shared
+AWT_LIBS = -L$(JAVA_HOME)/jre/lib/$(MACHINE_ARCH) -ljawt -shared
 
 GTK_PREFIX = swt-gtk
 GTK_LIB = lib$(GTK_PREFIX)-$(WS_PREFIX)-$(SWT_VERSION).so
@@ -59,7 +59,7 @@
 GTK_CFLAGS = `pkg-config --cflags gtk+-2.0`
 GTK_LIBS = -x -shared `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0
 	
-all: make_swt make_awt make_gnome make_gtk make_kde
+all: make_swt make_awt $(MAKE_GNOME) make_gtk
 
 make_swt: $(SWT_LIB)
 
@@ -80,16 +80,16 @@
 make_gnome: $(GNOME_LIB)
 
 $(GNOME_LIB): $(GNOME_OBJECTS)
-	gcc -o $@ $(GNOME_OBJECTS) $(GNOME_LIBS)
+	$(CC) -o $@ $(GNOME_OBJECTS) $(GNOME_LIBS)
 
 gnome.o: gnome.c
-	gcc $(GNOME_CFLAGS) -c -o gnome.o gnome.c
+	$(CC) $(GNOME_CFLAGS) -c -o gnome.o gnome.c
 
 gnome_structs.o: gnome_structs.c
-	gcc $(GNOME_CFLAGS) -c -o gnome_structs.o gnome_structs.c
+	$(CC) $(GNOME_CFLAGS) -c -o gnome_structs.o gnome_structs.c
 
 gnome_stats.o: gnome_stats.c
-	gcc $(GNOME_CFLAGS) -c -o gnome_stats.o gnome_stats.c
+	$(CC) $(GNOME_CFLAGS) -c -o gnome_stats.o gnome_stats.c
 
 make_kde: $(KDE_LIB)
 
