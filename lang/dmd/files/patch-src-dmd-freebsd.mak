--- ../../src/dmd/freebsd.mak.orig	2011-07-09 11:27:44.000000000 -0700
+++ ../../src/dmd/freebsd.mak	2011-08-06 21:26:42.816062642 -0700
@@ -3,9 +3,7 @@
 TK=tk
 ROOT=root
 
-MODEL=32
-
-CC=g++ -m$(MODEL)
+CC=c++
 
 #OPT=-g -g3
 #OPT=-O2
@@ -95,7 +93,7 @@
 all: dmd
 
 dmd: $(DMD_OBJS)
-	gcc -m$(MODEL) -lstdc++ -lpthread $(COV) $(DMD_OBJS) -o dmd
+	cc -lstdc++ -lpthread $(COV) $(DMD_OBJS) -o dmd
 
 clean:
 	rm -f $(DMD_OBJS) dmd optab.o id.o impcnvgen idgen id.c id.h \
@@ -468,7 +466,7 @@
 	$(CC) -c $(GFLAGS) -I$(ROOT) $<
 
 strtold.o: $C/strtold.c
-	gcc -m$(MODEL) -c $C/strtold.c
+	cc -c $C/strtold.c
 
 struct.o: struct.c
 	$(CC) -c $(CFLAGS) $<
