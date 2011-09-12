--- ../../src/dmd/posix.mak.orig	2011-09-07 20:10:32.000000000 -0700
+++ ../../src/dmd/posix.mak	2011-09-10 13:43:29.014432697 -0700
@@ -29,8 +29,6 @@
 TK=tk
 ROOT=root
 
-MODEL=32
-
 ifeq (OSX,$(TARGET))
     ## See: http://developer.apple.com/documentation/developertools/conceptual/cross_development/Using/chapter_3_section_2.html#//apple_ref/doc/uid/20002000-1114311-BABGCAAB
     ENVP= MACOSX_DEPLOYMENT_TARGET=10.3
@@ -47,7 +45,7 @@
     LDFLAGS=-lm -lstdc++ -lpthread
 endif
 
-CC=g++ -m$(MODEL) $(TARGET_CFLAGS)
+CC=g++ $(TARGET_CFLAGS)
 
 #OPT=-g -g3
 #OPT=-O2
@@ -141,7 +139,7 @@
 all: dmd
 
 dmd: $(DMD_OBJS)
-	$(ENVP) gcc -o dmd -m$(MODEL) $(COV) $(DMD_OBJS) $(LDFLAGS)
+	$(ENVP) gcc -o dmd $(COV) $(DMD_OBJS) $(LDFLAGS)
 
 clean:
 	rm -f $(DMD_OBJS) dmd optab.o id.o impcnvgen idgen id.c id.h \
@@ -511,7 +509,7 @@
 	$(CC) -c $(GFLAGS) -I$(ROOT) $<
 
 strtold.o: $C/strtold.c
-	gcc -m$(MODEL) -c $<
+	gcc -c $<
 
 struct.o: struct.c
 	$(CC) -c $(CFLAGS) $<
