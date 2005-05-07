--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_linux.mak	Fri Apr  1 13:55:11 2005
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak	Sat Apr  9 13:48:50 2005
@@ -49,8 +49,8 @@
 GNOMECFLAGS = `pkg-config --cflags gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0`
 GNOMELIBS = `pkg-config --libs-only-L gnome-vfs-module-2.0 libgnome-2.0 libgnomeui-2.0` -lgnomevfs-2 -lgnome-2 -lgnomeui-2
 
-KDE_LIBS = -shared -L$(KDE_LIB_PATH) -lkdecore -lkparts -L$(QT_HOME)/lib -lqt
-KDE_CFLAGS = -fno-rtti -c -O -I$(KDE_INCLUDE_PATH) -I$(QT_HOME)/include -I$(JAVA_HOME)/include
+KDE_LIBS = -shared -L$(KDE_LIB_PATH) -lkdecore -lkparts -L$(QT_HOME)/lib -lqt-mt
+KDE_CFLAGS = -fno-rtti -c -O -I$(KDE_INCLUDE_PATH) -I$(QT_HOME)/include -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd
 
 # Uncomment for Native Stats tool
 #NATIVE_STATS = -DNATIVE_STATS
@@ -65,6 +65,7 @@
 	-Wno-non-virtual-dtor \
 	-fPIC \
 	-I./ \
+	-I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd \
 	${GECKO_INCLUDES} \
 	${SWT_PTR_CFLAGS}
 	
@@ -82,14 +83,14 @@
 CFLAGS = -O -Wall \
 		-DSWT_VERSION=$(SWT_VERSION) \
 		$(NATIVE_STATS) \
-		-DLINUX -DGTK \
-		-I$(JAVA_HOME)/include \
-		-fpic \
+		-DFREEBSD -DGTK \
+		-I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/freebsd -I$(X11BASE)/include \
+		-fpic -fPIC \
 		${SWT_PTR_CFLAGS}
-LIBS = -shared -fpic
+LIBS = -shared -fpic -fPIC
 
 
-all: make_swt make_atk make_gnome make_awt make_kde
+all: make_swt make_atk $(MAKE_GNOME) make_awt
 
 #
 # SWT libs
