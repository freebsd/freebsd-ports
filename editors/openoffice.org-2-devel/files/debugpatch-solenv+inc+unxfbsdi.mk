--- ../solenv/inc/unxfbsdi.mk.orig	Thu Jun  5 08:44:59 2003
+++ ../solenv/inc/unxfbsdi.mk	Tue Jun 10 17:30:40 2003
@@ -92,12 +92,12 @@
 CDEFS+= $(PTHREAD_CFLAGS) -D_REENTRANT
 
 # flags for C and C++ Compile
-CFLAGS+= -w -c $(INCLUDE)
+CFLAGS+= -g -ggdb -w -c $(INCLUDE)
 CFLAGS+= -I/usr/X11R6/include
 
 # flags for the C++ Compiler
-CFLAGSCC= -pipe -fno-rtti
-CFLAGSCXX= -pipe -fno-for-scope -fpermissive -fno-rtti
+CFLAGSCC= -g -ggdb -pipe -fno-rtti
+CFLAGSCXX= -g -ggdb -pipe -fno-for-scope -fpermissive -fno-rtti
 
 # Flags for enabling exception handling
 CFLAGSEXCEPTIONS= -fexceptions
