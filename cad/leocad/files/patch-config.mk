$FreeBSD$

--- config.mk.orig	Mon Sep 18 21:06:37 2000
+++ config.mk	Sat Mar  2 19:21:24 2002
@@ -4,11 +4,11 @@
 
 default: all
 
-CC	:= gcc
-CXX	:= g++
+CC	?= gcc
+CXX	?= g++
 
 # (Add a -g for debugging)
-CPPFLAGS += -O2 -Wall
+CPPFLAGS += -Wall
 
 # Add compile options, such as -I option to include jpeglib's headers
 # CPPFLAGS += -I/home/fred/jpeglib
@@ -33,9 +33,10 @@
 
 OS 	   := -DLC_LINUX
 OSDIR 	   := linux
-PREFIX     := /usr/local
+PREFIX     := /usr/X11R6
 GTK_CONFIG := gtk12-config
-CPPFLAGS   += -L/usr/local/lib
+CPPFLAGS   += ${CFLAGS} -L%%LOCALBASE%%/lib -I%%LOCALBASE%%/include %%PTHREAD_CFLAGS%%
+LDFLAGS    += -L%%LOCALBASE%%/lib %%PTHREAD_LIBS%%
 
 endif
 
