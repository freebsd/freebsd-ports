--- ../solenv/inc/unxbsdi.mk.orig	Wed Oct 24 19:21:47 2001
+++ ../solenv/inc/unxbsdi.mk	Tue Mar  5 13:50:24 2002
@@ -1,77 +1,119 @@
 # mak file fuer unxbsdi
+ASM=gcc
+AFLAGS=-x assembler-with-cpp -c $(CDEFS)
 
-ASM=
-AFLAGS=
+SOLAR_JAVA=TRUE
+JAVAFLAGSDEBUG=-g
 
-cc=gcc -c
-CC=g++ -c
-CDEFS+=-D_PTHREADS -D_REENTRANT
-CDEFS+=-D_STD_NO_NAMESPACE -D_VOS_NO_NAMESPACE -D_UNO_NO_NAMESPACE
-CDEFS+=-DNO_INET_ON_DEMAND -DX86 -DNEW_SOLAR -DNCIfeature
-CFLAGS+=-w -c $(INCLUDE)
-CFLAGSCC=-pipe -mpentium
+# filter for supressing verbose messages from linker
+#not needed at the moment
+#LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
+
+# _PTHREADS is needed for the stl
+CDEFS+=-D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=400 -D
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
+# name of C++ Compiler
+CC=g++
+# name of C Compiler
+cc=gcc
+# flags for C and C++ Compiler
+CFLAGS=-w -c $(INCLUDE) -I$(SOLARENV)/unxbsdi/usr/include
+# flags for the C++ Compiler
+CFLAGSCC= -pipe
+# Flags for enabling exception handling
 CFLAGSEXCEPTIONS=-fexceptions
+# Flags for disabling exception handling
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
-CFLAGSCXX=-pipe -mpentium -fguiding-decls -frtti
 
-CFLAGSOBJGUIST=
-CFLAGSOBJCUIST=
-CFLAGSOBJGUIMT=
-CFLAGSOBJCUIMT=
-CFLAGSSLOGUIMT=	-fPIC
+# Compiler flags for compiling static object in single threaded environment with graphical user interface
+CFLAGSOBJGUIST= -fPIC
+# Compiler flags for compiling static object in single threaded environment with character user interface
+CFLAGSOBJCUIST= -fPIC
+# Compiler flags for compiling static object in multi threaded environment with graphical user interface
+CFLAGSOBJGUIMT= -fPIC
+# Compiler flags for compiling static object in multi threaded environment with character user interface
+CFLAGSOBJCUIMT= -fPIC
+# Compiler flags for compiling shared object in multi threaded environment with graphical user interface
+CFLAGSSLOGUIMT= -fPIC
+# Compiler flags for compiling shared object in multi threaded environment with character user interface
 CFLAGSSLOCUIMT=	-fPIC
-CFLAGSPROF=     -pg
-CFLAGSDEBUG=	-g
 CFLAGSDBGUTIL=
-# die zusaetzlichen Optimierungsschalter schalten alle Optimierungen ein, die zwischen -O und -O2 liegen und
-# per Schalter einschaltbar sind. Dennoch gibt es einen Unterschied: einige Files im Writer werden
-# misoptimiert wenn -O2 eingeschaltet ist und waehrend die untenstehenden Schalter funktionieren.
-CFLAGSOPT=-O -fcse-follow-jumps -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fforce-mem -fcaller-saves -fgcse -frerun-cse-after-loop -frerun-loop-opt -fschedule-insns2 -fregmove -foptimize-register-move
-#CFLAGSOPT=-O2
+# Compiler flags for profiling
+CFLAGSPROF=
+# Compiler flags for debugging
+CFLAGSDEBUG=-g
+# Compiler flags for enabling optimazations
+CFLAGSOPT=-O2
+# Compiler flags for disabling optimazations
 CFLAGSNOOPT=-O
+# Compiler flags for discibing the output path
 CFLAGSOUTOBJ=-o
 
+# switches for dynamic and static linking
 STATIC=			-Bstatic
 DYNAMIC=		-Bdynamic
 
-THREADLIB=
-LINK= gcc
+# name of linker
+LINK=gcc
+
+# default linker flags
 LINKFLAGS=
-.IF "$(PRJNAME)"=="osl" ||  "$(PRJNAME)"=="rtl" 
-LINKFLAGSSHLGUI= -shared -nostdlib
-LINKFLAGSSHLCUI= -shared -nostdlib
-.ELSE
-LINKFLAGSSHLGUI= -shared -nostdlib /usr/lib/c++rt0.o
-LINKFLAGSSHLCUI= -shared -nostdlib /usr/lib/c++rt0.o
-.ENDIF
-LINKFLAGSAPPGUI= -L/nw386/dev/s/solenv/unxbsdi/lib -lpthread_init -lpthread
-LINKFLAGSAPPCUI= -L/nw386/dev/s/solenv/unxbsdi/lib -lpthread_init -lpthread
 LINKFLAGSTACK=
 LINKFLAGSPROF=
-LINKFLAGSDEBUG=
+LINKFLAGSDEBUG=-g
 LINKFLAGSOPT=
 
-_SYSLIBS= -lpthread -lgcc -lc -lm 
-_X11LIBS= -L/usr/X11R6/lib -lXext -lX11
+.IF "$(NO_BSYMBOLIC)"==""
+.IF "$(PRJNAME)" != "envtest"
+LINKFLAGSSHLGUI+=-Wl,-Bsymbolic
+LINKFLAGSSHLCUI+=-Wl,-Bsymbolic
+.ENDIF
+.ENDIF                         # "$(NO_BSYMBOLIC)"==""
+
+LINKVERSIONMAPFLAG=-Wl,--version-script
+
+SONAME_SWITCH=-Wl,-h
+
+# Sequence of libs does matter !
 
-STDLIBCPP= -lstdc++
+STDLIBCPP=-lstdc++
+
+# default objectfilenames to link
 
 STDOBJGUI=
 STDSLOGUI=
 STDOBJCUI=
 STDSLOCUI=
 
-STDLIBGUIST=  ${_X11LIBS} ${_SYSLIBS}
-STDLIBCUIST=              ${_SYSLIBS}
-STDLIBGUIMT=  ${_X11LIBS} ${_SYSLIBS}
-STDLIBCUIMT=              ${_SYSLIBS}
-STDSHLGUIMT=
-STDSHLCUIMT=
-
-LIBMGR=			ar
-LIBFLAGS=		-r
-LIBEXT=			.a
+# libraries for linking applications
+STDLIBCUIST=-lm
+STDLIBGUIMT=-lXaw -lXt -lX11 -lpthread -lm
+STDLIBCUIMT=-lpthread -lm
+STDLIBGUIST=-lXaw -lXt -lX11 -lm
+# libraries for linking shared libraries
+STDSHLGUIMT=-lXaw -lXt -lX11 -lXext -lpthread -lm -lgcc
+STDSHLCUIMT=-lpthread -lm -lgcc
+
+# STLport always needs pthread. This may yield some redundant -lpthread
+# but that doesn't matter.
+LIBSTLPORT=$(DYNAMIC) -lstlport2_gcc -lpthread
+LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC) -lpthread
+
+# name of library manager
+LIBMGR=ar
+LIBFLAGS=-r
 
+# tool for generating import libraries
 IMPLIB=
 IMPLIBFLAGS=
 
@@ -79,14 +121,12 @@
 MAPSYMFLAGS=
 
 RC=irc
-RCFLAGS=		-fo$@ $(RCFILES)
+RCFLAGS=-fo$@ $(RCFILES)
 RCLINK=
 RCLINKFLAGS=
 RCSETVERSION=
 
-DLLPOSTFIX=		bi
-DLLPRE=			lib
-DLLPOST=		.so.1.0
-
-LDUMP=
-
+# platform specific identifier for shared libs
+DLLPOSTFIX=bi
+DLLPRE=lib
+DLLPOST=.so
