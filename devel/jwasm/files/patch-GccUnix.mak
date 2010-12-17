--- GccUnix.mak.orig	2009-06-07 14:07:37.000000000 -0500
+++ GccUnix.mak	2009-06-07 14:09:18.000000000 -0500
@@ -14,7 +14,7 @@
 #cflags stuff
 
 ifeq ($(DEBUG),0)
-extra_c_flags = -DNDEBUG -O2
+extra_c_flags = -DNDEBUG ${CFLAGS}
 OUTD=GccUnixR
 else
 extra_c_flags = -DDEBUG_OUT -g
@@ -23,7 +23,7 @@
 
 c_flags =-D__UNIX__ $(extra_c_flags)
 
-CC = gcc
+#CC = cc
 
 .SUFFIXES:
 .SUFFIXES: .c .o
