--- ../solenv/inc/unxfbsdi.mk.orig	Sat Jan 10 03:59:13 2004
+++ ../solenv/inc/unxfbsdi.mk	Fri Mar 12 21:39:05 2004
@@ -211,7 +211,7 @@
 LIBSALCPPRT*=-Wl,--whole-archive -lsalcpprt -Wl,--no-whole-archive
 
 # STLport always needs pthread.
-LIBSTLPORT=$(DYNAMIC) -lstlport_gcc $(PTHREAD_LIBS)
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc $(STDLIBCPP) $(PTHREAD_LIBS)
 LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC) $(PTHREAD_LIBS)
 
 # name of library manager
