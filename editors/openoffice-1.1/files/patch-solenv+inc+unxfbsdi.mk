--- ../solenv/inc/unxfbsdi.mk.org	Thu Aug 28 07:35:37 2003
+++ ../solenv/inc/unxfbsdi.mk	Fri Aug 29 22:42:08 2003
@@ -200,12 +200,12 @@
 # libraries for linking applications
 STDLIBCUIST=-lm
 STDLIBGUIST=-lXaw -lXt -lX11 -lm
-STDLIBGUIMT=-lXaw -lXt -lX11 $(PTHREAD_LIBS) -lm -lstlport_gcc
-STDLIBCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+STDLIBGUIMT=-lXaw -lXt -lX11 $(PTHREAD_LIBS) -lm
+STDLIBCUIMT=$(PTHREAD_LIBS) -lm
 
 # libraries for linking shared libraries
-STDSHLGUIMT=-lXaw -lXt -lX11 -lXext $(PTHREAD_LIBS) -lm -lstlport_gcc
-STDSHLCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+STDSHLGUIMT=-lXaw -lXt -lX11 -lXext $(PTHREAD_LIBS) -lm
+STDSHLCUIMT=$(PTHREAD_LIBS) -lm
 
 LIBSALCPPRT*=-Wl,--whole-archive -lsalcpprt -Wl,--no-whole-archive
 
