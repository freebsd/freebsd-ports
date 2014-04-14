--- ../../src/dmd/posix.mak.orig	2012-12-31 12:16:46.000000000 -0800
+++ ../../src/dmd/posix.mak	2013-09-27 22:38:06.189546090 -0700
@@ -49,7 +49,6 @@
 TK=tk
 ROOT=root
 
-MODEL=32
 ifneq (x,x$(MODEL))
     MODEL_FLAG=-m$(MODEL)
 endif
@@ -73,7 +72,7 @@
     LDFLAGS=-lm -lstdc++ -lpthread
 endif
 
-HOST_CC=g++
+HOST_CC=$(CXX)
 CC=$(HOST_CC) $(MODEL_FLAG) $(TARGET_CFLAGS)
 
 #OPT=-g -g3
@@ -572,7 +571,7 @@
 	$(CC) -c $(GFLAGS) -I$(ROOT) $<
 
 strtold.o: $C/strtold.c
-	gcc $(MODEL_FLAG) -I$(ROOT) -c $<
+	$(CC) $(MODEL_FLAG) -I$(ROOT) -c $<
 
 struct.o: struct.c
 	$(CC) -c $(CFLAGS) $<
