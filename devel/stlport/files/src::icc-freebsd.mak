#
# Note : This makefile is for Intel(R) C++ Compiler
#

#
# compiler
#
#CC= icc
#CXX= icpc
#CFLAGS= -O -ip -axiMKW
#CXXFLAGS= -O -ip -axiMKW

#
# Basename for libraries
#
LIB_BASENAME = libstlport_icc

#
# guts for common stuff
#
#
LINK=ar cr
# Using icc here is a hack while icpc on FreeBSD is set up to automatically
# link against libstlport_icc.
DYN_LINK=$(CC) -mt -shared -o

OBJEXT=o
DYNEXT=so
STEXT=a
RM=rm -rf
PATH_SEP=/
MKDIR=mkdir -p
COMP=ICC-FREEBSD
INSTALL_STEP = install_unix 

all: gmake_message  all_dynamic all_static symbolic_links 

gmake_message:
	echo "Note : this makefile requires gmake on FreeBSD"

include common_macros.mak

WARNING_FLAGS= -w1

CXXFLAGS_COMMON = -I$(STLPORT_DIR) $(WARNING_FLAGS) $(PTHREAD_CFLAGS) -D_REENTRANT

CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) $(CXXFLAGS)
CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) $(CXXFLAGS) -KPIC

CXXFLAGS_DEBUG_static = $(CXXFLAGS_COMMON) -O -g
CXXFLAGS_DEBUG_dynamic = $(CXXFLAGS_COMMON) -O -KPIC

CXXFLAGS_STLDEBUG_static = $(CXXFLAGS_DEBUG_static) -D_STLP_DEBUG
CXXFLAGS_STLDEBUG_dynamic = $(CXXFLAGS_DEBUG_dynamic) -D_STLP_DEBUG

include common_percent_rules.mak
include common_rules.mak
