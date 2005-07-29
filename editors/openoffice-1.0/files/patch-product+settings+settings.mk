--- product/settings/settings.mk.orig	Sat Jan 18 18:23:17 2003
+++ product/settings/settings.mk	Sat Jan 18 18:37:12 2003
@@ -225,3 +226,72 @@
 
 endif
 
+ifeq "$(PLATFORM)" "FreeBSD"
+# Settings for FreeBSD using gcc compiler
+
+OS=FREEBSD
+PLATFORM=freebsd
+PS=/
+LINK=$(CC)
+LIB=$(CC)
+ECHO=@echo
+MKDIR=mkdir -p
+CAT=cat
+OBJ_EXT=o
+SHAREDLIB_EXT=so
+SHAREDLIB_PRE=lib
+SHAREDLIB_OUT=$(OUT_LIB)
+PACKAGE_LIB_DIR=freebsd_x86.plt
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
+CC_FLAGS=-c -g
+else
+CC_FLAGS=-c -O
+endif
+SDK_JAVA_INCLUDES = -I$(OO_SDK_JAVA_HOME)/include -I$(OO_SDK_JAVA_HOME)/include/freebsd -I$(OO_SDK_JAVA_HOME)/include/linux
+CC_INCLUDES=-I. -I/usr/include -I$(OUT)/inc/examples -I$(PRJ)/include
+STL_INCLUDES=-I$(OO_STLPORT_HOME)/stlport
+CC_DEFINES=-DUNX -DGCC -DFREEBSD -DCPPU_ENV=$(CPPU_ENV)
+
+# define for used compiler necessary for UNO
+#-DCPPU_ENV=gcc2 -- gcc 2.91/2.95
+#-DCPPU_ENV=gcc3 -- gcc3 3.0
+
+CC_OUTPUT_SWITCH=-o
+
+LIBRARY_LINK_FLAGS=-shared
+EXE_LINK_FLAGS=-Wl -export-dynamic
+LINK_LIBS=-L$(OUT)/lib -L$(PRJ)/$(PLATFORM)/lib -L$(OFFICE_PROGRAM_PATH) -pthread
+
+endif
