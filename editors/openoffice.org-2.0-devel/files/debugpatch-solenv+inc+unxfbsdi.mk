--- ../solenv/inc/unxfbsdi.mk.orig	Mon Jul 22 00:40:56 2002
+++ ../solenv/inc/unxfbsdi.mk	Mon Jul 22 00:42:02 2002
@@ -92,12 +92,12 @@
 CDEFS+= $(PTHREAD_CFLAGS) -D_REENTRANT
 
 # flags for C and C++ Compile
-CFLAGS+= -w -c $(INCLUDE)
+CFLAGS+= -g -ggdb -w -c $(INCLUDE)
 CFLAGS+= -I/usr/X11R6/include
 
 # flags for the C++ Compiler
-CFLAGSCC= -pipe
-CFLAGSCXX= -pipe -fno-for-scope -fpermissive
+CFLAGSCC= -g -ggdb -pipe
+CFLAGSCXX= -g -ggdb -pipe -fno-for-scope -fpermissive
 
 # Flags for enabling exception handling
 CFLAGSEXCEPTIONS= -fexceptions
