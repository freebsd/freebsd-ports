--- Makefile.X.orig	Mon Nov 27 23:36:18 2006
+++ Makefile.X	Mon Nov 27 23:37:51 2006
@@ -15,7 +15,8 @@
 LD	= gcc	# Linker used
 
 CFLAGS	= -Wall -O2 -fomit-frame-pointer \
-	  -DLSB_FIRST -DUNIX_X -DUNIX -DMITSHM -DHAVE_CLOCK -DSOUND -DZLIB
+	  -DLSB_FIRST -DUNIX_X -DUNIX -DMITSHM -DHAVE_CLOCK -DSOUND -DZLIB \
+	  -I${PREFIX}/include
 
 OBJECTS = ADAMEm.o Coleco.o Z80.o \
           DSP.o Sound.o X.o Z80Debug.o Bitmap.o Unix.o
@@ -26,7 +27,7 @@
 	rm -f *.o *~
 
 adamem: $(OBJECTS)
-	$(LD) -s -Wl,-Map,adamem.map -L/usr/X11R6/lib \
+	$(LD) -s -Wl,-Map,adamem.map -L${LOCALBASE}/lib \
               -o adamem $(OBJECTS) -lXext -lX11 -lz
 
 cvem: adamem
@@ -42,7 +43,7 @@
 	$(LD) -s -o keys keys.o
 
 adamem.snd: makedata
-	makedata
+	./makedata
 
 makedata.o: makedata.c
 makedata: makedata.o
