--- ./src/scripts/unix-secure.mak.orig	Fri Aug 11 19:08:00 2006
+++ ./src/scripts/unix-secure.mak	Sat Aug 12 10:56:39 2006
@@ -12,17 +12,14 @@
 # Usage: make -f scripts/unix-secure.mak
 
 
-prefix=/usr/local
+prefix=${PREFIX}
 exec_prefix=${prefix}
 bindir=${exec_prefix}/bin
-mandir=${prefix}/man
-man1dir=${mandir}/man1
+man1dir=${MAN1PREFIX}/man/man1
 
-CC = cc
-LD = $(CC)
-MAKE = make
-CFLAGS  = -O
-LDFLAGS = -s
+CFLAGS  ?= -O
+LDFLAGS += -s -L${LOCALBASE}/lib
+CFLAGS  += -I${LOCALBASE}/include
 
 OPTIPNG  = optipng
 PNGXLIB  = pngxtern.a
@@ -35,7 +32,7 @@
 
 
 $(OPTIPNG): $(OBJS) $(LIBS)
-	$(LD) -o $(OPTIPNG) $(LDFLAGS) $(OBJS) $(LIBS) -lpng -lz
+	$(CC) -o $(OPTIPNG) $(LDFLAGS) $(OBJS) $(LIBS) -lpng -lz
 
 
 .c.o:
