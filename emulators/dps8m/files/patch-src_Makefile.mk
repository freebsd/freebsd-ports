--- src/Makefile.mk.orig	2023-08-13 10:22:22 UTC
+++ src/Makefile.mk
@@ -294,7 +294,7 @@ endif
 
 _DEBUGOPTFLAG := -g
 ifndef TESTING
-  OPTFLAGS = -O3 $(_DEBUGOPTFLAG) -U_FORTIFY_SOURCE -fno-stack-protector
+# OPTFLAGS = -O3 $(_DEBUGOPTFLAG) -U_FORTIFY_SOURCE -fno-stack-protector
   ifdef DUMA
     CFLAGS   += -I../dps8 -I. -include dps8_duma.h
     OPTFLAGS += -DDUMA=1
