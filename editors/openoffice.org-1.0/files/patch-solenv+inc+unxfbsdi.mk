--- ../solenv/inc/unxfbsdi.mk.orig	Tue Jan  7 16:22:18 2003
+++ ../solenv/inc/unxfbsdi.mk	Sat Jan 18 13:04:17 2003
@@ -1,84 +1,139 @@
-
 # mak file fuer unxfbsdi
 
-ASM=
-AFLAGS=
+ASM=$(CC)
+AFLAGS=-x assembler-with-cpp -c $(CDEFS)
 
 SOLAR_JAVA=TRUE
 JAVAFLAGSDEBUG=-g
 
+# filter for supressing verbose messages from linker
+# not needed at the moment
 LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
 
+# options for C and C++ Compiler
+CDEFS+=-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=400 -DOSVERSION=$(OSVERSION)
+CDEFS+=$(PTHREAD_CFLAGS)
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
+
+# flags for C and C++ Compiler
+CFLAGS+=-w -c $(INCLUDE) -I$(SOLARENV)/unxfbsdi/usr/include
+CFLAGS+=-I/usr/X11R6/include
+
+# flags for the C++ Compiler
+CFLAGSCC=-pipe
+CFLAGSCXX=-pipe -fno-for-scope -fpermissive
+
+# Flags for enabling exception handling
+CFLAGSEXCEPTIONS=-fexceptions
+
+# Flags for disabling exception handling
+CFLAGS_NO_EXCEPTIONS=-fno-exceptions
+
+# Compiler flags for compiling static object in single threaded
+# environment with graphical user interface
+CFLAGSOBJGUIST=-fPIC
+
+# Compiler flags for compiling static object in single threaded
+# environment with character user interface
+CFLAGSOBJCUIST=-fPIC
+
+# Compiler flags for compiling static object in multi threaded
+# environment with graphical user interface
+CFLAGSOBJGUIMT=-fPIC
 
-CC=				gcc
-CXX=				g++
-CDEFS+=			-D_USE_NAMESPACE=1 -DX86 -DNEW_SOLAR -DSTLPORT_VERSION=400
-CDEFS+=			-D_REENTRANT -D_PTHREADS -D_THREAD_SAFE
-CFLAGS+= -w -c $(INCLUDE)
-CFLAGS+= -I/usr/X11R6/include
-CFLAGSCC= -pipe
-CFLAGSCXX= -pipe -fno-for-scope -fpermissive
-CFLAGSEXCEPTIONS= -fexceptions
-CFLAGS_NO_EXCEPTIONS= -fno-exceptions
-CFLAGSOBJGUIST= -fPIC
-CFLAGSOBJCUIST= -fPIC
-CFLAGSOBJGUIMT= -fPIC
-CFLAGSOBJCUIMT= -fPIC
-CFLAGSSLOGUIMT=	-fPIC
-CFLAGSSLOCUIMT=	-fPIC
-CFLAGSPROF=     -pg
-CFLAGSDEBUG=	-g
+# Compiler flags for compiling static object in multi threaded
+# environment with character user interface
+CFLAGSOBJCUIMT=-fPIC
+
+# Compiler flags for compiling shared object in multi threaded
+# environment with graphical user interface
+CFLAGSSLOGUIMT=-fPIC
+
+# Compiler flags for compiling shared object in multi threaded
+# environment with character user interface
+CFLAGSSLOCUIMT=-fPIC
+
+# Compiler flags for profiling
+CFLAGSPROF=-pg
+
+# Compiler flags for debugging
+CFLAGSDEBUG=-g -ggdb
 CFLAGSDBGUTIL=
-CFLAGSOPT= -O2
-CFLAGSNOOPT= -O
-CFLAGSOUTOBJ= -o
-
-STATIC=	-Wl,-Bstatic
-DYNAMIC= -Wl,-Bdynamic
-
-#THREADLIB= -pthread
-LINK= gcc
-# -v -nostdlib
+
+# Compiler flags to enable optimizations
+# -02 is broken for FreeBSD
+CFLAGSOPT=-O
+
+# Compiler flags to disable optimizations
+# -0 is broken for STLport
+CFLAGSNOOPT=-O0
+
+# Compiler flags for the output path
+CFLAGSOUTOBJ=-o
+
+# switches for dynamic and static linking
+STATIC=-Wl,-Bstatic
+DYNAMIC=-Wl,-Bdynamic
+
+LINK=$(CXX)
 LINKFLAGS=
-LINKFLAGSAPPGUI= -Wl,-export-dynamic
-LINKFLAGSAPPCUI= -Wl,-export-dynamic
+
+# linker flags for linking applications
+LINKFLAGSAPPGUI= 
+LINKFLAGSAPPCUI= 
+
+# linker flags for linking shared libraries
 LINKFLAGSSHLGUI= -shared
 LINKFLAGSSHLCUI= -shared
 LINKFLAGSTACK=
 LINKFLAGSPROF=
 LINKFLAGSDEBUG=-g
-LINKFLAGSOPT=
+LINKFLAGSOPT=-O
 
 .IF "$(NO_BSYMBOLIC)"==""
 .IF "$(PRJNAME)" != "envtest"
-LINKFLAGSSHLGUI+= -Wl,-Bsymbolic
-LINKFLAGSSHLCUI+= -Wl,-Bsymbolic
+LINKFLAGSSHLGUI+=-Wl,-Bsymbolic
+LINKFLAGSSHLCUI+=-Wl,-Bsymbolic
 .ENDIF
 .ENDIF
 
 LINKVERSIONMAPFLAG=-Wl,--version-script
 
+# Sequence of libs does matter !
 STDLIBCPP=-lstdc++
 
-# _SYSLIBS= -L/usr/lib -lm
-# _X11LIBS= -L/usr/X11R6/lib -lXext -lX11
-# _CXXLIBS= -L/usr/lib -lstdc++ -L/usr/local/lib
+# libraries for linking applications
+STDLIBCUIST=-lm
+STDLIBGUIST=-lXaw -lXt -lX11 -lm
+STDLIBGUIMT=-lXaw -lXt -lX11 $(PTHREAD_LIBS) -lm -lstlport_gcc
+STDLIBCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+
+# libraries for linking shared libraries
+STDSHLGUIMT=-lXaw -lXt -lX11 -lXext $(PTHREAD_LIBS) -lm -lstlport_gcc
+STDSHLCUIMT=$(PTHREAD_LIBS) -lm -lstlport_gcc
+
+# STLport always needs pthread.
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc $(PTHREAD_LIBS)
+LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC) $(PTHREAD_LIBS)
 
+# default objectfilenames to lin
 STDOBJGUI=
 STDSLOGUI=
 STDOBJCUI=
 STDSLOCUI=
 
-STDLIBCUIST=-lm
-STDLIBGUIST=-lX11 -lm
-STDLIBGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDLIBCUIMT=-pthread -lm -lstlport_gcc
-STDSHLGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDSHLCUIMT=-pthread -lm -lstlport_gcc
-
-LIBMGR=			ar
-LIBFLAGS=		-r
-LIBEXT=			.a
+LIBMGR=ar
+LIBFLAGS=-r
+LIBEXT=.a
 
 IMPLIB=
 IMPLIBFLAGS=
@@ -87,12 +142,12 @@
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
