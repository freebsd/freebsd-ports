--- ./src/scripts/gcc-syslib.mak.orig	Mon Jul 24 20:49:09 2006
+++ ./src/scripts/gcc-syslib.mak	Mon Jul 24 20:53:49 2006
@@ -15,18 +15,16 @@
 # Usage: make -f scripts/gcc-syslib.mak
 
 
-prefix=/usr/local
+prefix=${PREFIX}
 exec_prefix=${prefix}
 bindir=${exec_prefix}/bin
-mandir=${prefix}/man
-man1dir=${mandir}/man1
+man1dir=${MAN1PREFIX}/man/man1
 
-CC = gcc
 LD = $(CC)
-CFLAGS  = -O2 -Wall
-LDFLAGS = -s
+CFLAGS  ?= -O2 -Wall
+LDFLAGS += -s
 
-OPTIPNG  = optipng$(EXE)
+OPTIPNG  = optipng
 PNGLIB   = libpng.a
 PNGXLIB  = pngxtern.a
 PNGMAK   = scripts/makefile.gcc
