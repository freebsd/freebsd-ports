#
# Note : this makefile is for Intel(R) C++ Compiler Version 6.0 !
#

#
# compiler
#
CC= icc
CXX= icpc

#
# Basename for libraries
#
LIB_BASENAME = libstlport_icc

#
# guts for common stuff
#
#
LINK=ar cr
DYN_LINK=$(CXX) -Qoption,ld,-BOOTSTRAPSTLPORT -mt -shared -o

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

CXXFLAGS_COMMON = -I${STLPORT_DIR} ${WARNING_FLAGS} ${PTHREAD_CFLAGS} -D_REENTRANT -mt

CXXFLAGS_RELEASE_static = $(CXXFLAGS_COMMON) -O -ip -axiMKW
CXXFLAGS_RELEASE_dynamic = $(CXXFLAGS_COMMON) -O -ip -axiMKW -KPIC

CXXFLAGS_DEBUG_static = $(CXXFLAGS_COMMON) -O -g
CXXFLAGS_DEBUG_dynamic = $(CXXFLAGS_COMMON) -O -g -KPIC

CXXFLAGS_STLDEBUG_static = $(CXXFLAGS_DEBUG_static) -D_STLP_DEBUG
CXXFLAGS_STLDEBUG_dynamic = $(CXXFLAGS_DEBUG_dynamic) -D_STLP_DEBUG

include common_percent_rules.mak
include common_rules.mak
