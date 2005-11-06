--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak.orig  Sat May 14 19:50:23 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak       Sat May 14 21:24:34 2005
@@ -70,7 +70,7 @@
 SWT_OBJECTS = swt.o callback.o
 AWT_OBJECTS = swt_awt.o
 SWTPI_OBJECTS = swt.o os.o os_structs.o os_custom.o os_stats.o
-CAIRO_OBJECTS = swt.o cairo.o cairo_structs.o cairo_stats.o cairo_custom.o
+CAIRO_OBJECTS = swt.o cairo.o cairo_structs.o cairo_stats.o
 ATK_OBJECTS = swt.o atk.o atk_structs.o atk_custom.o atk_stats.o
 GNOME_OBJECTS = swt.o gnome.o gnome_structs.o gnome_stats.o
 MOZILLA_OBJECTS = swt.o xpcom.o xpcom_custom.o xpcom_structs.o xpcom_stats.o
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
+all: make_swt make_atk $(MAKE_GNOME) make_awt $(MAKE_MOZILLA) $(MAKE_CAIRO)
 
 #
 # SWT libs
@@ -123,8 +124,6 @@
 
 cairo.o: cairo.c cairo.h swt.h
 	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo.c
-cairo_custom.o: cairo_custom.c cairo_structs.h cairo.h swt.h
-	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo_custom.c
 cairo_structs.o: cairo_structs.c cairo_structs.h cairo.h swt.h
 	$(CC) $(CFLAGS) $(CAIROCFLAGS) -c cairo_structs.c
 cairo_stats.o: cairo_stats.c cairo_structs.h cairo.h cairo_stats.h swt.h
