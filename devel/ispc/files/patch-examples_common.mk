--- examples/common.mk.orig	2016-07-08 11:13:52 UTC
+++ examples/common.mk
@@ -4,18 +4,18 @@ TASK_LIB=-lpthread
 TASK_OBJ=objs/tasksys.o
 
 CXX=clang++
-CXXFLAGS+=-Iobjs/ -O2
+CXXFLAGS+=-Iobjs/ -O2 -std=c++11 -I$(LOCALBASE)/include
 CC=clang
 CCFLAGS+=-Iobjs/ -O2
 
-LIBS=-lm $(TASK_LIB) -lstdc++
+LIBS=-lm $(TASK_LIB) -lstdc++ -L$(LOCALBASE)/lib -ltbb
 ISPC=ispc
 ISPC_FLAGS+=-O2
 ISPC_HEADER=objs/$(ISPC_SRC:.ispc=_ispc.h)
 
-ARCH:=$(shell uname -m | sed -e s/x86_64/x86/ -e s/i686/x86/ -e s/arm.*/arm/ -e s/sa110/arm/)
+_ARCH:=$(shell uname -m | sed -e s/amd64/x86/ -e s/i.86/x86/ -e s/arm.*/arm/ -e s/sa110/arm/)
 
-ifeq ($(ARCH),x86)
+ifeq ($(_ARCH),x86)
   ISPC_OBJS=$(addprefix objs/, $(ISPC_SRC:.ispc=)_ispc.o)
   COMMA=,
   ifneq (,$(findstring $(COMMA),$(ISPC_IA_TARGETS)))
@@ -53,11 +53,11 @@ ifeq ($(ARCH),x86)
     CXXFLAGS += -m64
     CCFLAGS += -m64
   endif
-else ifeq ($(ARCH),arm)
+else ifeq ($(_ARCH),arm)
   ISPC_OBJS=$(addprefix objs/, $(ISPC_SRC:.ispc=_ispc.o))
   ISPC_TARGETS=$(ISPC_ARM_TARGETS)
 else
-  $(error Unknown architecture $(ARCH) from uname -m)
+  $(error Unknown architecture $(_ARCH) from uname -m)
 endif
 
 CPP_OBJS=$(addprefix objs/, $(CPP_SRC:.cpp=.o))
