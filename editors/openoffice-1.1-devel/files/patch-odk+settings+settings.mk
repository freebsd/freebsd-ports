http://www.openoffice.org/issues/show_bug.cgi?id=40190
http://www.openoffice.org/issues/show_bug.cgi?id=24142

--- odk/settings/settings.mk.orig	Sun Jan 25 18:41:02 2004
+++ odk/settings/settings.mk	Sun Jan 25 18:45:09 2004
@@ -368,3 +368,85 @@
 
 endif
 
+ifeq "$(PLATFORM)" "FreeBSD"
+# Settings for FreeBSD using gcc compiler
+
+PROCTYPE := $(shell uname -m)
+
+    
+# Default is freebsd on a intel machine    
+PLATFORM=FreeBSD
+PACKAGE_LIB_DIR=freebsd_x86.plt
+JAVA_PROC_TYPE=i386
+
+OS=FREEBSD
+PS=/
+CC=gcc
+LINK=gcc
+LIB=gcc
+ECHO=@echo
+MKDIR=mkdir -p
+CAT=cat
+OBJ_EXT=o
+SHAREDLIB_EXT=so
+SHAREDLIB_PRE=lib
+SHAREDLIB_OUT=$(OUT_LIB)
+    
+GCC_VERSION=$(shell $(CC) -dumpversion)
+
+ifeq "$(shell echo $(GCC_VERSION) | cut -c 1)" "3"
+COMID=gcc3
+CPPU_ENV=gcc3
+else
+COMID=GCC
+CPPU_ENV=gcc2
+endif
+
+OSEP=\<
+CSEP=\>
+QUOTE=$(subst S,\,S)
+QM=\"
+    
+DEL=rm -f
+DELRECURSIVE=rm -rf
+COPY=cp
+URLPREFIX=file://
+
+# Include UDK version numbers
+include $(PRJ)/include/udkversion.mk
+
+SALLIB=-lsal
+CPPULIB=-lcppu
+CPPUHELPERLIB=-lcppuhelper$(COMID)
+SALHELPERLIB=-lsalhelper$(COMID)
+STLPORTLIB=-lstlport_gcc
+
+EMPTYSTRING=
+PATH_SEPARATOR=:
+
+# -O is necessary for inlining (see gcc documentation)
+ifeq "$(DEBUG)" "yes"
+CC_FLAGS=-c -g -fpic -DPIC -fno-rtti %%PTHREAD_CFLAGS%%
+else
+CC_FLAGS=-c -O -fpic -DPIC -fno-rtti %%PTHREAD_CFLAGS%%
+endif
+
+SDK_JAVA_INCLUDES = -I$(OO_SDK_JAVA_HOME)/include -I$(OO_SDK_JAVA_HOME)/include/freebsd
+CC_INCLUDES=-I. -I/usr/include -I$(OUT)/inc/examples -I$(PRJ)/include
+STL_INCLUDES=-I$(OO_SDK_HOME)/include/stl
+CC_DEFINES=-DUNX -DGCC -DFREEBSD -DCPPU_ENV=$(CPPU_ENV)
+
+# define for used compiler necessary for UNO
+#-DCPPU_ENV=gcc2 -- gcc 2.91/2.95
+#-DCPPU_ENV=gcc3 -- gcc3 3.0
+
+CC_OUTPUT_SWITCH=-o
+
+LIBRARY_LINK_FLAGS=-shared '-Wl,-rpath,$$ORIGIN'
+
+EXE_LINK_FLAGS=-Wl
+LINK_LIBS=-L$(OUT)/lib -L$(PRJ)/$(PLATFORM)/lib -L$(OFFICE_PROGRAM_PATH) %%PTHREAD_LIBS%%
+LINK_JAVA_LIBS=-L$(OO_SDK_JAVA_HOME)/jre/lib/$(JAVA_PROC_TYPE)
+
+endif
+
