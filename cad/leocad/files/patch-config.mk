--- config.mk.orig	2012-03-17 22:55:49.000000000 +0100
+++ config.mk	2012-07-11 20:57:38.000000000 +0200
@@ -6,11 +6,12 @@
 
 default: all
 
-CC	:= gcc
-CXX	:= g++
+CC	?= gcc
+CXX	?= g++
 
 # (Add a -g for debugging)
-CPPFLAGS += -O2 -Wall
+CPPFLAGS += -Wall -I%%LOCALBASE%%/include %%PTHREAD_CFLAGS%%
+LDFLAGS += %%PTHREAD_LIBS%%
 
 # Add compile options, such as -I option to include jpeglib's headers
 # CPPFLAGS += -I/home/fred/jpeglib
