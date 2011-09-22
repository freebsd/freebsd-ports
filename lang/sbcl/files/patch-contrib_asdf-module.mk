--- contrib/asdf-module.mk.orig	2011-09-21 17:44:49.000000000 -0700
+++ contrib/asdf-module.mk	2011-09-21 17:45:24.000000000 -0700
@@ -1,4 +1,4 @@
-CC=cc
+CC?=cc
 
 # We need to extend flags to the C compiler and the linker
 # here. sb-posix, sb-grovel, and sb-bsd-sockets depends upon these
