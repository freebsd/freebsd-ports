--- ../solenv/inc/unxfbsdi.mk.orig	Fri Jan 31 16:46:52 2003
+++ ../solenv/inc/unxfbsdi.mk	Wed Mar  5 20:23:28 2003
@@ -61,50 +61,115 @@
 #*************************************************************************
 
 # mak file for unxfbsdi
+ASM=$(CC)
+AFLAGS=-x assembler-with-cpp -c $(CDEFS)
 
-ASM=
-AFLAGS=
+# filter for supressing verbose messages from linker
+#not needed at the moment
+#LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
+
+# this is a platform with JAVA support
+.IF "$(SOLAR_JAVA)"!=""
+JAVADEF=-DSOLAR_JAVA
+.IF "$(debug)"==""
+JAVA_RUNTIME=-ljava
+.ELSE
+JAVA_RUNTIME=-ljava_g
+.ENDIF
+.ENDIF
 
-SOLAR_JAVA=TRUE
-JAVAFLAGSDEBUG=-g
+# name of C++ Compiler
+CXX*=g++
+# name of C Compiler
+CC*=gcc
 
+# filter for supressing verbose messages from linker
+# not needed at the moment
 LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
 
+# options for C and C++ Compiler
+CDEFS+=	-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=450 -DOSVERSION=$(OSVERSION)
+CDEFS+= $(PTHREAD_CFLAGS) -D_REENTRANT
 
-CC=				gcc
-CXX=			g++
-CDEFS+=			-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=400
-CDEFS+=			-D_REENTRANT -D_PTHREADS -D_THREAD_SAFE
+# flags for C and C++ Compile
 CFLAGS+= -w -c $(INCLUDE)
 CFLAGS+= -I/usr/X11R6/include
+
+# flags for the C++ Compiler
 CFLAGSCC= -pipe
 CFLAGSCXX= -pipe -fno-for-scope -fpermissive
+
+# Flags for enabling exception handling
 CFLAGSEXCEPTIONS= -fexceptions
 CFLAGS_NO_EXCEPTIONS= -fno-exceptions
+
+# Compiler flags for compiling static object in single threaded
+# environment with graphical user interface
 CFLAGSOBJGUIST= -fPIC
+
+# Compiler flags for compiling static object in single threaded
+# environment with character user interface
 CFLAGSOBJCUIST= -fPIC
+
+# Compiler flags for compiling static object in multi threaded
+# environment with graphical user interface
 CFLAGSOBJGUIMT= -fPIC
+
+# Compiler flags for compiling static object in multi threaded
+# environment with character user interface
 CFLAGSOBJCUIMT= -fPIC
+
+# Compiler flags for compiling shared object in multi threaded
+# environment with graphical user interface
 CFLAGSSLOGUIMT=	-fPIC
+
+# Compiler flags for compiling shared object in multi threaded
+# environment with character user interface
 CFLAGSSLOCUIMT=	-fPIC
+
+# Compiler flags for profilin
 CFLAGSPROF=     -pg
+
+# Compiler flags for debugging
 CFLAGSDEBUG=	-g
 CFLAGSDBGUTIL=
-CFLAGSOPT= -O2
-CFLAGSNOOPT= -O
+
+# Compiler flags to enable optimizations
+# -02 is broken for FreeBSD
+CFLAGSOPT= -O
+
+# Compiler flags to disable optimizations
+# -0 is broken for STLport for FreeBSD
+CFLAGSNOOPT= -O0
+
+# Compiler flags for the output path
 CFLAGSOUTOBJ= -o
 
+# Enable all warnings
+CFLAGSWALL=-Wall
+
+# Set default warn level
+CFLAGSDFLTWARN=-w
+
+# switches for dynamic and static linking
 STATIC=	-Wl,-Bstatic
 DYNAMIC= -Wl,-Bdynamic
 
-#THREADLIB= -pthread
-LINK= gcc
-# -v -nostdlib
-LINKFLAGS=
-LINKFLAGSAPPGUI= -Wl,-export-dynamic
-LINKFLAGSAPPCUI= -Wl,-export-dynamic
+# name of linker
+LINK*=$(CC)
+
+# default linker flags
+# LINKFLAGSRUNPATH*=-Wl,-rpath\''$$ORIGIN'\'
+LINKFLAGS=-z combreloc $(LINKFLAGSRUNPATH)
+
+# linker flags for linking applications
+LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec
+LINKFLAGSAPPCUI= -Wl,-export-dynamic -Wl,--noinhibit-exec
+
+# linker flags for linking shared libraries
 LINKFLAGSSHLGUI= -shared
 LINKFLAGSSHLCUI= -shared
+
 LINKFLAGSTACK=
 LINKFLAGSPROF=
 LINKFLAGSDEBUG=-g
@@ -119,28 +184,41 @@
 
 LINKVERSIONMAPFLAG=-Wl,--version-script
 
+# Sequence of libs does matter !
 STDLIBCPP=-lstdc++
 
 # _SYSLIBS= -L/usr/lib -lm
 # _X11LIBS= -L/usr/X11R6/lib -lXext -lX11
 # _CXXLIBS= -L/usr/lib -lstdc++ -L/usr/local/lib
 
+# default objectfilenames to link
 STDOBJGUI=
 STDSLOGUI=
 STDOBJCUI=
 STDSLOCUI=
 
+# libraries for linking applications
 STDLIBCUIST=-lm
-STDLIBGUIST=-lX11 -lm
-STDLIBGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDLIBCUIMT=-pthread -lm -lstlport_gcc
-STDSHLGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDSHLCUIMT=-pthread -lm -lstlport_gcc
-
-LIBMGR=			ar
-LIBFLAGS=		-r
+STDLIBGUIST=-lXaw -lXt -lX11 -lm
+STDLIBGUIMT=-lXaw -lXt -lX11 $(PTHREAD_LIBS) -lm -lstlport_gcc
+STDLIBCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+
+# libraries for linking shared libraries
+STDSHLGUIMT=-lXaw -lXt -lX11 -lXext $(PTHREAD_LIBS) -lm -lstlport_gcc
+STDSHLCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+
+LIBSALCPPRT*=-Wl,--whole-archive -lsalcpprt -Wl,--no-whole-archive
+
+# STLport always needs pthread.
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc $(PTHREAD_LIBS)
+LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC) $(PTHREAD_LIBS)
+
+# name of library manager
+LIBMGR=ar
+LIBFLAGS=-r
 LIBEXT=			.a
 
+# tool for generating import libraries
 IMPLIB=
 IMPLIBFLAGS=
 
@@ -148,12 +226,12 @@
 MAPSYMFLAGS=
 
 RC=irc
-RCFLAGS=		-fo$@ $(RCFILES)
+RCFLAGS=-fo$@ $(RCFILES)
 RCLINK=
 RCLINKFLAGS=
 RCSETVERSION=
 
-DLLPOSTFIX=		fi
-DLLPRE=			lib
-DLLPOST=		.so
-LDUMP=
+# platform specific identifier for shared libs
+DLLPOSTFIX=fi
+DLLPRE=lib
+DLLPOST=.so
