--- ../solenv/inc/unxfbsdi.mk.orig	Sat Mar  9 01:11:29 2002
+++ ../solenv/inc/unxfbsdi.mk	Sat Mar  9 01:08:23 2002
@@ -13,7 +13,7 @@
 cc=				gcc
 CC=				g++
 CDEFS+=			-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=400
-CDEFS+=			-D_REENTRANT -D_PTHREADS -D_THREAD_SAFE
+CDEFS+=			-D_REENTRANT -D_PTHREADS -D_THREAD_SAFE -DOSVERSION=$(OSVERSION)
 CFLAGS+= -w -c $(INCLUDE)
 CFLAGS+= -I/usr/X11R6/include
 CFLAGSCC= -pipe
@@ -42,12 +42,12 @@
 LINKFLAGS=
 LINKFLAGSAPPGUI= -Wl,-export-dynamic
 LINKFLAGSAPPCUI= -Wl,-export-dynamic
-LINKFLAGSSHLGUI= -shared
-LINKFLAGSSHLCUI= -shared
+LINKFLAGSSHLGUI= -shared -Wl,-export-dynamic
+LINKFLAGSSHLCUI= -shared -Wl,-export-dynamic
 LINKFLAGSTACK=
 LINKFLAGSPROF=
 LINKFLAGSDEBUG=-g
-LINKFLAGSOPT=
+LINKFLAGSOPT=-O
 
 .IF "$(NO_BSYMBOLIC)"==""
 .IF "$(PRJNAME)" != "envtest"
