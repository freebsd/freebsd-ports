Index: solenv/inc/unxfbsdi.mk
===================================================================
RCS file: /cvs/tools/solenv/inc/unxfbsdi.mk,v
retrieving revision 1.4.4.1
diff -u -r1.4.4.1 unxfbsdi.mk
--- solenv/inc/unxfbsdi.mk	7 Jan 2003 15:22:18 -0000	1.4.4.1
+++ solenv/inc/unxfbsdi.mk	18 Jul 2005 04:00:18 -0000
@@ -1,49 +1,162 @@
+#*************************************************************************
+#
+#   $RCSfile:$
+#
+#   $Revision:$
+#
+#   last change: $Author:$
+#
+#   The Contents of this file are made available subject to the terms of
+#   either of the following licenses
+#
+#          - GNU Lesser General Public License Version 2.1
+#          - Sun Industry Standards Source License Version 1.1
+#
+#   Sun Microsystems Inc., October, 2000
+#
+#   GNU Lesser General Public License Version 2.1
+#   =============================================
+#   Copyright 2000 by Sun Microsystems, Inc.
+#   901 San Antonio Road, Palo Alto, CA 94303, USA
+#
+#   This library is free software; you can redistribute it and/or
+#   modify it under the terms of the GNU Lesser General Public
+#   License version 2.1, as published by the Free Software Foundation.
+#
+#   This library is distributed in the hope that it will be useful,
+#   but WITHOUT ANY WARRANTY; without even the implied warranty of
+#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+#   Lesser General Public License for more details.
+#
+#   You should have received a copy of the GNU Lesser General Public
+#   License along with this library; if not, write to the Free Software
+#   Foundation, Inc., 59 Temple Place, Suite 330, Boston,
+#   MA  02111-1307  USA
+#
+#
+#   Sun Industry Standards Source License Version 1.1
+#   =================================================
+#   The contents of this file are subject to the Sun Industry Standards
+#   Source License Version 1.1 (the "License"); You may not use this file
+#   except in compliance with the License. You may obtain a copy of the
+#   License at http://www.openoffice.org/license.html.
+#
+#   Software provided under this License is provided on an "AS IS" basis,
+#   WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
+#   WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
+#   MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
+#   See the License for the specific provisions governing your rights and
+#   obligations concerning the Software.
+#
+#   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
+#
+#   Copyright: 2000 by Sun Microsystems, Inc.
+#
+#   All Rights Reserved.
+#
+#   Contributor(s): _______________________________________
+#
+#
+#
+#*************************************************************************
 
-# mak file fuer unxfbsdi
-
+# mk file for unxfbsdi
 ASM=
 AFLAGS=
 
 SOLAR_JAVA=TRUE
 JAVAFLAGSDEBUG=-g
 
-LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
-
+# filter for supressing verbose messages from linker
+#not needed at the moment
+#LINKOUTPUT_FILTER=" |& $(SOLARENV)$/bin$/msg_filter"
+
+# options for C and C++ Compiler
+CDEFS+=-DX86 -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=400 -DOSVERSION=$(OSVERSION) $(PTHREAD_CFLAGS)
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
+# name of C++ Compiler
+CXX*=g++
+# name of C Compiler
+CC*=gcc
+# flags for C and C++ Compiler
+# do not use standard header search paths
+# if installed elsewhere
+.IF "$(BUILD_SOSL)"!=""
+CFLAGS=
+.ENDIF
+CFLAGS+=-fmessage-length=0 -c $(INCLUDE)
+# flags for the C++ Compiler
+CFLAGSCC= -pipe -mcpu=pentiumpro
+# Flags for enabling exception handling
+CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
+# Flags for disabling exception handling
+CFLAGS_NO_EXCEPTIONS=-fno-exceptions
+
+# -fpermissive should be removed as soon as possible
+CFLAGSCXX= -pipe -mcpu=pentiumpro -fno-for-scope -fpermissive
+
+#  FIXME: This 'if' does not work due to a sequence error in files.
+#.IF "$(CCNUMVER)"<"000300020000"
+#CFLAGSCXX+=-fno-rtti
+#.ENDIF
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
+# Compiler flags for debugging
+CFLAGSDEBUG=-g
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
+# Compiler flags for enabling optimazations
+# CFLAGSOPT=-O2
+# reduce to -O1 to avoid optimisation problems
+CFLAGSOPT=-O1
+# Compiler flags for disabling optimazations
+CFLAGSNOOPT=-O
+# Compiler flags for discibing the output path
+CFLAGSOUTOBJ=-o
+# Enable all warnings
+CFLAGSWALL=-Wall
+# Set default warn level
+CFLAGSDFLTWARN=-w
+
+# switches for dynamic and static linking
+STATIC		= -Wl,-Bstatic
+DYNAMIC		= -Wl,-Bdynamic
+
+# name of linker
+LINK*=$(CC)
+# default linker flags
 LINKFLAGS=
-LINKFLAGSAPPGUI= -Wl,-export-dynamic
-LINKFLAGSAPPCUI= -Wl,-export-dynamic
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
@@ -51,35 +164,46 @@
 
 .IF "$(NO_BSYMBOLIC)"==""
 .IF "$(PRJNAME)" != "envtest"
-LINKFLAGSSHLGUI+= -Wl,-Bsymbolic
-LINKFLAGSSHLCUI+= -Wl,-Bsymbolic
-.ENDIF
+LINKFLAGSSHLGUI+=-Wl,-Bsymbolic
+LINKFLAGSSHLCUI+=-Wl,-Bsymbolic
 .ENDIF
+.ENDIF				# "$(NO_BSYMBOLIC)"==""
 
 LINKVERSIONMAPFLAG=-Wl,--version-script
 
-STDLIBCPP=-lstdc++
+SONAME_SWITCH=-Wl,-h
 
-# _SYSLIBS= -L/usr/lib -lm
-# _X11LIBS= -L/usr/X11R6/lib -lXext -lX11
-# _CXXLIBS= -L/usr/lib -lstdc++ -L/usr/local/lib
+# Sequence of libs does matter !
 
+STDLIBCPP=-lstdc++
+
+# default objectfilenames to link
 STDOBJGUI=
 STDSLOGUI=
 STDOBJCUI=
 STDSLOCUI=
 
+# libraries for linking applications
 STDLIBCUIST=-lm
+STDLIBGUIMT=-lX11 $(PTHREAD_LIBS) -lm
+STDLIBCUIMT=$(PTHREAD_LIBS) -lm
 STDLIBGUIST=-lX11 -lm
-STDLIBGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDLIBCUIMT=-pthread -lm -lstlport_gcc
-STDSHLGUIMT=-lX11 -lXext -pthread -lm -lstlport_gcc
-STDSHLCUIMT=-pthread -lm -lstlport_gcc
-
-LIBMGR=			ar
-LIBFLAGS=		-r
-LIBEXT=			.a
+# libraries for linking shared libraries
+STDSHLGUIMT=-lX11 -lXext $(PTHREAD_LIBS) -lm
+STDSHLCUIMT=$(PTHREAD_LIBS) -lm
+STDSHLGUIST=-lX11 -lXext -lm
+STDSHLCUIST=-lm
+
+LIBSTLPORT=$(DYNAMIC) -lstlport_gcc -lstdc++
+LIBSTLPORTST=$(STATIC) -lstlport_gcc $(DYNAMIC)
+
+#FILLUPARC=$(STATIC) -lsupc++ $(DYNAMIC)
+
+# name of library manager
+LIBMGR=ar
+LIBFLAGS=-r
 
+# tool for generating import libraries
 IMPLIB=
 IMPLIBFLAGS=
 
@@ -87,12 +211,13 @@
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
+
