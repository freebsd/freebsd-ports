
$FreeBSD$

--- ../config/FreeBSD.mk.orig	Sat Jul 29 03:50:35 2000
+++ ../config/FreeBSD.mk	Tue Dec 18 11:43:06 2001
@@ -37,19 +37,21 @@
 
 include $(MOD_DEPTH)/config/UNIX.mk
 
-CC			= gcc
-CCC			= g++
+CCC			= $(CXX)
 RANLIB			= ranlib
 
+# During FreeBSD port build, CFLAGS contains all of the optimizations
+# flags desired...
+OPTIMIZER		= $(MOZ_OPTIMIZE_FLAGS)
+
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
-OS_REL_CFLAGS		= -Di386
 CPU_ARCH		= x86
 endif
 CPU_ARCH_TAG		= _$(CPU_ARCH)
 
-OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -pipe $(THREAD_FLAG) -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -pipe -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
 #
 # The default implementation strategy for FreeBSD is pthreads.
@@ -60,8 +62,8 @@
 else
 USE_PTHREADS		= 1
 IMPL_STRATEGY		= _PTH
-DEFINES			+= -D_THREAD_SAFE
-THREAD_FLAG		+= -pthread
+DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
+DSO_LDOPTS		+= -pthread
 endif
 
 ARCH			= freebsd
@@ -75,7 +77,7 @@
 endif
 
 DSO_CFLAGS		= -fPIC
-DSO_LDOPTS		= -Bshareable
+DSO_LDOPTS		+= -Bshareable
 
 MKSHLIB			= $(LD) $(DSO_LDOPTS)
 
