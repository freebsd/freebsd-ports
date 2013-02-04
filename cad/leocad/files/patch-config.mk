--- config.mk.orig	2012-12-14 07:50:24.000000000 +0900
+++ config.mk	2012-12-15 04:42:02.000000000 +0900
@@ -6,17 +6,18 @@
 
 default: all
 
-CC    := gcc
-CXX   := g++
+CC    ?= gcc
+CXX   ?= g++
 OSDIR := linux
 
 # (Add a -g for debugging)
-CPPFLAGS += -O2 -Wall
+CPPFLAGS += -Wall
 
 ### FreeBSD configuration
 
 ifeq ($(shell uname), FreeBSD)
-CPPFLAGS += -L/usr/local/lib
+CPPFLAGS += -I%%LOCALBASE%%/include %%PTHREAD_LIBS%%
+LDFLAGS  += -L%%LOCALBASE%%/lib %%PTHREAD_LIBS%%
 endif
 
 ### Default directory
