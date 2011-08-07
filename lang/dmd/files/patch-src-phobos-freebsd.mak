--- ../../src/phobos/freebsd.mak.orig	2011-06-24 17:47:13.431230979 -0700
+++ ../../src/phobos/freebsd.mak	2011-06-24 17:49:46.357713495 -0700
@@ -12,12 +12,11 @@
 LIB=libphobos.a
 
 MAKEFILE=freebsd.mak
-MODEL=32
 
-CFLAGS=-O -m$(MODEL)
+CFLAGS=-O
 #CFLAGS=-g -m$(MODEL)
 
-DFLAGS=-O -release -w -m$(MODEL)
+DFLAGS=-O -release -w
 #DFLAGS=-unittest -w -m$(MODEL)
 
 RM=rm -f
@@ -248,7 +247,7 @@
 	./unittest
 
 cov : $(SRCS) $(LIB)
-	$(DMD) -cov -unittest -ofcov -m$(MODEL) unittest.d $(SRCS) $(LIB)
+	$(DMD) -cov -unittest -ofcov unittest.d $(SRCS) $(LIB)
 	./cov
 
 
@@ -258,13 +257,13 @@
 #	cd internal/gc
 #	make -f $(MAKEFILE) dmgc.a
 #	cd ../..
-	make DMD=$(DMD) MODEL=$(MODEL) -C ./internal/gc -f $(MAKEFILE)
+	make DMD=$(DMD) -C ./internal/gc -f $(MAKEFILE)
 
 $(ZLIB_OBJS):
 #	cd etc/c/zlib
 #	make -f $(MAKEFILE)
 #	cd ../../..
-	make -C ./etc/c/zlib -f $(MAKEFILE) MODEL=$(MODEL)
+	make -C ./etc/c/zlib -f $(MAKEFILE)
 
 ###
 
