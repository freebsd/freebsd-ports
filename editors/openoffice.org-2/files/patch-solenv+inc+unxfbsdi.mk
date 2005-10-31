Issuetracker : #i56956#
CWS          : N/A
Author:      : <maho@openoffice.org> (JCA)
Description  : FreeBSD porting : catch up recent version of solenv/inc/unxlngi6.mk
catch up recent version of solenv/inc/unxlngi6.mk and STLPORT_VERSION is 450 in FreeBSD

--- solenv/inc/unxfbsdi.mk	Wed Oct  5 20:33:12 2005
+++ solenv/inc/unxfbsdi.mk	Mon Oct 24 11:13:39 2005
@@ -45,7 +45,7 @@
 #LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
 
 # _PTHREADS is needed for the stl
-CDEFS+=$(PTHREAD_CFLAGS) -DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=400
+CDEFS+=$(PTHREAD_CFLAGS) -DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=450
 
 # enable visibility define in "sal/types.h"
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
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
 
