--- config.mk.orig	2012-12-14 12:16:05.000000000 -0500
+++ config.mk	2012-12-14 12:16:51.000000000 -0500
@@ -6,12 +6,13 @@ ERROR_SETTING=2> /dev/null
 
 default: all
 
-CC    := gcc
-CXX   := g++
+CC    ?= cc
+CXX   ?= c++
 OSDIR := linux
 
 # (Add a -g for debugging)
-CPPFLAGS += -O2 -Wall
+CPPFLAGS += -Wall -I%%LOCALBASE%%/include %%PTHREAD_CFLAGS%%
+LDFLAGS	+= %%PTHREAD_LIBS%%
 
 ### FreeBSD configuration
 
