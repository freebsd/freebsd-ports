--- ../solenv/inc/unxfbsdi.mk.orig	Mon Jul 22 00:40:56 2002
+++ ../solenv/inc/unxfbsdi.mk	Mon Jul 22 00:42:02 2002
@@ -25,12 +25,12 @@
 .ENDIF
 
 # flags for C and C++ Compiler
-CFLAGS+=-w -c $(INCLUDE) -I$(SOLARENV)/unxfbsdi/usr/include
+CFLAGS+=-g -ggdb -w -c $(INCLUDE) -I$(SOLARENV)/unxfbsdi/usr/include
 CFLAGS+=-I/usr/X11R6/include
 
 # flags for the C++ Compiler
-CFLAGSCC=-pipe
-CFLAGSCXX=-pipe -fno-for-scope -fpermissive
+CFLAGSCC=-g -ggdb -pipe
+CFLAGSCXX=-g -ggdb -pipe -fno-for-scope -fpermissive
 
 # Flags for enabling exception handling
 CFLAGSEXCEPTIONS=-fexceptions
