--- fgkicker.mak.orig	2014-06-15 17:50:51.745429612 +0800
+++ fgkicker.mak	2014-06-15 17:50:58.109420658 +0800
@@ -28,7 +28,7 @@ MAKEOPTIONS = -j1
 
 GCC = gcc
 
-CC = gcc
+CC ?= gcc
 
 CFLAGS = $(INCLUDES) $(CWARNFLAGS) $(CDEBUGFLAGS) $(COPTIMIZEFLAGS) $(CLANGFLAGS) $(CCODEFLAGS) `pkg-config --cflags gtk+-2.0`
 
