Issuetracker : #iXXXXX#
CWS          : N/A
Author       : <maho@openoffice.org> (JCA)
Description  : FreeBSD porting : catch up recent version of solenv/inc/unxlngi5.mk
catch up recent version of solenv/inc/unxlngi5.mk

--- solenv/inc/unxfbsdi.mk.orig	Tue May  4 01:27:08 2004
+++ solenv/inc/unxfbsdi.mk	Mon Oct 24 11:39:05 2005
@@ -60,16 +60,21 @@
 #
 #*************************************************************************
 
-# mak file for unxfbsdi
-ASM=$(CC)
-AFLAGS=-x assembler-with-cpp -c $(CDEFS)
+# ma file for unxfbsdi
+ASM=
+AFLAGS=
+
+SOLAR_JAVA*=TRUE
+JAVAFLAGSDEBUG=-g
 
 # filter for supressing verbose messages from linker
 #not needed at the moment
 #LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
 
+# _PTHREADS is needed for the stl
+CDEFS+= -DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=450 -DOSVERSION=$(OSVERSION) $(PTHREAD_CFLAGS)
+
 # this is a platform with JAVA support
-SOLAR_JAVA*=TRUE
 .IF "$(SOLAR_JAVA)"!=""
 JAVADEF=-DSOLAR_JAVA
 .IF "$(debug)"==""
@@ -83,89 +88,81 @@
 CXX*=g++
 # name of C Compiler
 CC*=gcc
+.IF "$(SYSBASE)"!=""
+CFLAGS_SYSBASE:=-isystem $(SYSBASE)$/usr$/include
+CXX+:=$(CFLAGS_SYSBASE)
+CC+:=$(CFLAGS_SYSBASE)
+.ENDIF          # "$(SYSBASE)"!=""
+# flags for C and C++ Compiler
+# do not use standard header search paths
+# if installed elsewhere
+.IF "$(BUILD_SOSL)"!=""
+CFLAGS=
+.ENDIF
+CFLAGS+=-fmessage-length=0 -c $(INCLUDE)
 
-# filter for supressing verbose messages from linker
-# not needed at the moment
-LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
-
-# options for C and C++ Compiler
-CDEFS+=	-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=450 -DOSVERSION=$(OSVERSION)
-CDEFS+= $(PTHREAD_CFLAGS) -D_REENTRANT
-
-# flags for C and C++ Compile
-CFLAGS+= -w -c $(INCLUDE)
-CFLAGS+= -I/usr/X11R6/include
+# flags to enable build with symbols; required for crashdump feature
+.IF "$(ENABLE_SYMBOLS)"=="SMALL"
+CFLAGSENABLESYMBOLS=-g1
+.ELSE
+CFLAGSENABLESYMBOLS=-g
+.ENDIF
 
 # flags for the C++ Compiler
-CFLAGSCC= -pipe -fno-rtti
-CFLAGSCXX= -pipe -fno-for-scope -fpermissive -fno-rtti
-
+CFLAGSCC= -pipe -mcpu=pentiumpro
 # Flags for enabling exception handling
-CFLAGSEXCEPTIONS= -fexceptions
-CFLAGS_NO_EXCEPTIONS= -fno-exceptions
-
-# Compiler flags for compiling static object in single threaded
-# environment with graphical user interface
-CFLAGSOBJGUIST= -fPIC
-
-# Compiler flags for compiling static object in single threaded
-# environment with character user interface
-CFLAGSOBJCUIST= -fPIC
-
-# Compiler flags for compiling static object in multi threaded
-# environment with graphical user interface
-CFLAGSOBJGUIMT= -fPIC
-
-# Compiler flags for compiling static object in multi threaded
-# environment with character user interface
-CFLAGSOBJCUIMT= -fPIC
-
-# Compiler flags for compiling shared object in multi threaded
-# environment with graphical user interface
-CFLAGSSLOGUIMT=	-fPIC
-
-# Compiler flags for compiling shared object in multi threaded
-# environment with character user interface
-CFLAGSSLOCUIMT=	-fPIC
-
-# Compiler flags for profilin
-CFLAGSPROF=     -pg
-
+CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
+# Flags for disabling exception handling
+CFLAGS_NO_EXCEPTIONS=-fno-exceptions
+
+# -fpermissive should be removed as soon as possible
+CFLAGSCXX= -pipe -mcpu=pentiumpro -fno-for-scope -fpermissive -fno-rtti
+
+# Compiler flags for compiling static object in single threaded environment with graphical user interface
+CFLAGSOBJGUIST=
+# Compiler flags for compiling static object in single threaded environment with character user interface
+CFLAGSOBJCUIST=
+# Compiler flags for compiling static object in multi threaded environment with graphical user interface
+CFLAGSOBJGUIMT=
+# Compiler flags for compiling static object in multi threaded environment with character user interface
+CFLAGSOBJCUIMT=
+# Compiler flags for compiling shared object in multi threaded environment with graphical user interface
+CFLAGSSLOGUIMT=-fpic
+# Compiler flags for compiling shared object in multi threaded environment with character user interface
+CFLAGSSLOCUIMT=-fpic
+# Compiler flags for profiling
+CFLAGSPROF=
 # Compiler flags for debugging
-CFLAGSDEBUG=	-g
+CFLAGSDEBUG=-g
 CFLAGSDBGUTIL=
-
-# Compiler flags to enable optimizations
-# -02 is broken for FreeBSD
-CFLAGSOPT= -O
-
-# Compiler flags to disable optimizations
-# -0 is broken for STLport for FreeBSD
-CFLAGSNOOPT= -O0
-
-# Compiler flags for the output path
-CFLAGSOUTOBJ= -o
-
+# Compiler flags for enabling optimazations
+# CFLAGSOPT=-O2
+# reduce to -O1 to avoid optimisation problems
+CFLAGSOPT=-O1
+# Compiler flags for disabling optimazations
+CFLAGSNOOPT=-O0
+# Compiler flags for discibing the output path
+CFLAGSOUTOBJ=-o
 # Enable all warnings
 CFLAGSWALL=-Wall
-
 # Set default warn level
 CFLAGSDFLTWARN=-w
 
 # switches for dynamic and static linking
-STATIC=	-Wl,-Bstatic
-DYNAMIC= -Wl,-Bdynamic
+STATIC		= -Wl,-Bstatic
+DYNAMIC		= -Wl,-Bdynamic
 
 # name of linker
-LINK=$(CC)
+LINK*=$(CC)
 
 # default linker flags
-# LINKFLAGSRUNPATH*=-Wl,-rpath\''$$ORIGIN'\'
-LINKFLAGS=$(LINKFLAGSRUNPATH)
+LINKFLAGSDEFS*=-z defs
+LINKFLAGSRUNPATH*=-Wl,-rpath,\''$$ORIGIN'\'
+LINKFLAGS=-z combreloc $(LINKFLAGSDEFS) $(LINKFLAGSRUNPATH)
 
 # linker flags for linking applications
-LINKFLAGSAPPGUI= -Wl,--noinhibit-exec
-LINKFLAGSAPPCUI= -Wl,--noinhibit-exec
+LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec
+LINKFLAGSAPPCUI= -Wl,-export-dynamic -Wl,--noinhibit-exec
 
 # linker flags for linking shared libraries
 LINKFLAGSSHLGUI= -shared
@@ -176,21 +173,16 @@
 LINKFLAGSDEBUG=-g
 LINKFLAGSOPT=
 
-.IF "$(NO_BSYMBOLIC)"==""
-.IF "$(PRJNAME)" != "envtest"
-LINKFLAGSSHLGUI+= -Wl,-Bsymbolic
-LINKFLAGSSHLCUI+= -Wl,-Bsymbolic
-.ENDIF
-.ENDIF
+# linker flags for optimization (symbol hashtable)
+# for now, applied to symbol scoped libraries, only
+LINKFLAGSOPTIMIZE*=-Wl,-O1
+LINKVERSIONMAPFLAG=$(LINKFLAGSOPTIMIZE) -Wl,--version-script
 
-LINKVERSIONMAPFLAG=-Wl,--version-script
+SONAME_SWITCH=-Wl,-h
 
 # Sequence of libs does matter !
-STDLIBCPP=-lstdc++
 
-# _SYSLIBS= -L/usr/lib -lm
-# _X11LIBS= -L/usr/X11R6/lib -lXext -lX11
-# _CXXLIBS= -L/usr/lib -lstdc++ -L/usr/local/lib
+STDLIBCPP=-lstdc++
 
 # default objectfilenames to link
 STDOBJGUI=
@@ -200,24 +192,26 @@
 
 # libraries for linking applications
 STDLIBCUIST=-lm
-STDLIBGUIST=-lXaw -lXt -lX11 -lm
-STDLIBGUIMT=-lXaw -lXt -lX11 $(PTHREAD_LIBS) -lm
+STDLIBGUIMT=-lX11 $(PTHREAD_LIBS) -lm
 STDLIBCUIMT=$(PTHREAD_LIBS) -lm
+STDLIBGUIST=-lX11 -lm
 
 # libraries for linking shared libraries
-STDSHLGUIMT=-lXaw -lXt -lX11 -lXext $(PTHREAD_LIBS) -lm
+STDSHLGUIMT=-lX11 -lXext $(PTHREAD_LIBS) -lm
 STDSHLCUIMT=$(PTHREAD_LIBS) -lm
+STDSHLGUIST=-lX11 -lXext -lm
+STDSHLCUIST=-lm
 
 LIBSALCPPRT*=-Wl,--whole-archive -lsalcpprt -Wl,--no-whole-archive
 
-# STLport always needs pthread.
-LIBSTLPORT=$(DYNAMIC) -lstlport_gcc $(STDLIBCPP) $(PTHREAD_LIBS)
-LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC) $(PTHREAD_LIBS)
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc -lstdc++
+LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC)
+
+#FILLUPARC=$(STATIC) -lsupc++ $(DYNAMIC)
 
 # name of library manager
 LIBMGR=ar
 LIBFLAGS=-r
-LIBEXT=			.a
 
 # tool for generating import libraries
 IMPLIB=
@@ -236,3 +230,4 @@
 DLLPOSTFIX=fi
 DLLPRE=lib
 DLLPOST=.so
+
