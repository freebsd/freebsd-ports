# platform_freebsd.GNU,v 4.21 2003/08/09 04:43:51 dhinton Exp

# platform_freebsd.GNU

VERSION := $(shell uname -r | sed -e "s/`uname -r | sed -e 's/.//'`//")
ifeq ($(VERSION),2)
versioned_so = 1
endif

ifndef exceptions
  exceptions = 1
endif

ifeq (,$(threads))
  threads = 1
endif

ifeq (,$(debug))
  debug = 0
endif

ifeq (,$(optimize))
  optimize = 1
endif

ssl=1
interface_repo=1
corba_messaging=1

CC              = gcc
CXX             = g++

CFLAGS          += %%CFLAGS%%
DCFLAGS         += -g
ifneq ($(VERSION),3)
  LDFLAGS       += -Wl,-rpath $(ACE_ROOT)/ace
endif
DLD             = $(CXX)
LD              = $(CXX)
PIC             = -fpic
AR              = ar
ARFLAGS         = ruv
RANLIB          = ranlib

SOFLAGS += $(CPPFLAGS) -shared
SOBUILD = $(COMPILE.cc) $(PIC) -o $(VSHDIR)$*.so $<
PRELIB = @echo

ifeq ($(threads),1)
LDFLAGS         += %%PTHREAD_LIBS%%
CFLAGS          += %%PTHREAD_CFLAGS%%
endif # threads

# Test for template instantiation, add to SOFLAGS if SONAME set, 
# add -E to LDFLAGS if using GNU ld
#
include $(ACE_ROOT)/include/makeinclude/platform_g++_common.GNU

CCFLAGS         += $(CFLAGS) $(TEMPLATES_FLAG)
