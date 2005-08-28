--- Makefile.X.orig	Fri Feb 14 04:53:43 1997
+++ Makefile.X	Wed Aug 24 16:01:47 2005
@@ -18,14 +18,14 @@
 # aware though, screen refresh is much slower when shared
 # memory is not used
 
-CC	= gcc	# C compiler used
-LD	= gcc	# Linker used
+CC	?= gcc	# C compiler used
+LD	?= gcc	# Linker used
 
-CFLAGS  = -Wall -fomit-frame-pointer -O2 -I/usr/X11/include \
+CFLAGS  += -Wall -fomit-frame-pointer -O2 -I${X11BASE}/include \
 	  -DLSB_FIRST -DHAVE_FTRUNCATE -DHAVE_CLOCK -DUNIX_X \
 	  -DSOUND -DMITSHM
 
-LFLAGS	= -s -L/usr/X11/lib
+LFLAGS	+= -L${X11BASE}/lib
 
 OBJECTS = M2000.o P2000.o Z80.o Z80Debug.o \
           Unix.o X.o
@@ -33,13 +33,13 @@
 all:    m2000 fontc splitape z80dasm
 
 m2000:	$(OBJECTS)
-	$(LD) $(LFLAGS) -o m2000 $(OBJECTS) -lXext -lX11
+	$(CC) $(LFLAGS) -o m2000 $(OBJECTS) -lXext -lX11
 fontc:	fontc.o
-	$(LD) $(LFLAGS) -o fontc fontc.o
+	$(CC) $(LFLAGS) -o fontc fontc.o
 splitape: splitape.o
-	$(LD) $(LFLAGS) -o splitape splitape.o
+	$(CC) $(LFLAGS) -o splitape splitape.o
 z80dasm: Z80Dasm.o
-	$(LD) $(LFLAGS) -o z80dasm Z80Dasm.o
+	$(CC) $(LFLAGS) -o z80dasm Z80Dasm.o
 
 M2000.o:    M2000.c P2000.h Z80.h Help.h Z80IO.h
 P2000.o:    P2000.c P2000.h Z80.h Z80IO.h
