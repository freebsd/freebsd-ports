STLPORT_VERSION is 450 for FreeBSD

--- solenv/inc/unxfbsdi.mk~	Thu Sep  8 18:52:53 2005
+++ solenv/inc/unxfbsdi.mk	Fri Sep 30 14:08:04 2005
@@ -45,7 +45,7 @@
 #LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
 
 # _PTHREADS is needed for the stl
-CDEFS+=$(PTHREAD_CFLAGS) -DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=400
+CDEFS+=$(PTHREAD_CFLAGS) -DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=450
 
 # enable visibility define in "sal/types.h"
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
--- solenv/inc/unxfbsdi.mk~	Sat Oct  1 08:52:58 2005
+++ solenv/inc/unxfbsdi.mk	Sat Oct  1 12:52:34 2005
@@ -190,8 +190,13 @@
 
 LIBSALCPPRT*=-Wl,--whole-archive -lsalcpprt -Wl,--no-whole-archive
 
+.IF "$(USE_STLP_DEBUG)" != ""
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc_stldebug
+LIBSTLPORTST=$(STATIC) -lstlport_gcc_stldebug $(DYNAMIC)
+.ELSE # "$(USE_STLP_DEBUG)" != ""
 LIBSTLPORT=$(DYNAMIC) -lstlport_gcc
 LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC)
+.ENDIF # "$(USE_STLP_DEBUG)" != ""
 
 #FILLUPARC=$(STATIC) -lsupc++ $(DYNAMIC)
 
