--- ../../src/dmd/posix.mak.orig	2012-04-10 22:34:58.000000000 -0700
+++ ../../src/dmd/posix.mak	2012-04-14 23:37:37.562325386 -0700
@@ -29,8 +29,6 @@
 TK=tk
 ROOT=root
 
-MODEL=32
-
 ifeq (OSX,$(TARGET))
     ## See: http://developer.apple.com/documentation/developertools/conceptual/cross_development/Using/chapter_3_section_2.html#//apple_ref/doc/uid/20002000-1114311-BABGCAAB
     ENVP= MACOSX_DEPLOYMENT_TARGET=10.3
@@ -48,7 +46,7 @@
 endif
 
 HOST_CC=g++
-CC=$(HOST_CC) -m$(MODEL) $(TARGET_CFLAGS)
+CC=$(HOST_CC) $(TARGET_CFLAGS)
 
 #OPT=-g -g3
 #OPT=-O2
@@ -144,7 +142,7 @@
 all: dmd
 
 dmd: $(DMD_OBJS)
-	$(ENVP) $(HOST_CC) -o dmd -m$(MODEL) $(COV) $(DMD_OBJS) $(LDFLAGS)
+	$(ENVP) $(HOST_CC) -o dmd $(COV) $(DMD_OBJS) $(LDFLAGS)
 
 clean:
 	rm -f $(DMD_OBJS) dmd optab.o id.o impcnvgen idgen id.c id.h \
@@ -523,7 +521,7 @@
 	$(CC) -c $(GFLAGS) -I$(ROOT) $<
 
 strtold.o: $C/strtold.c
-	gcc -m$(MODEL) -I$(ROOT) -c $<
+	gcc -I$(ROOT) -c $<
 
 struct.o: struct.c
 	$(CC) -c $(CFLAGS) $<
