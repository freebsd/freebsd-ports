# $FreeBSD$

SHELL                  = /bin/sh

CADDIR                 = ${PREFIX}
BINDIR                 = ${CADDIR}/bin
LIBDIR                 = ${CADDIR}/lib
MANDIR                 = ${CADDIR}/man
SYSDIR                 = ${CADDIR}/lib/magic/sys
SCMDIR                 = ${CADDIR}/lib/magic/scm

SCRIPTS                = ${MAGICDIR}/scripts

RM                     = rm -f
CP                     = cp
AR                     = ar
ARFLAGS                = crv
LD                     = ld -r
RANLIB                 = ranlib

CPP                    = /usr/bin/cpp -P -traditional
CPPFLAGS               = -I. -I${MAGICDIR}
DFLAGS                 =  -DFILE_LOCKS -DHAVE_READLINE -DNONMANHATTAN -DUSE_NEW_MACROS

READLINE_DEFS          = 
READLINE_LIBS          =  -lreadline -ltermcap

DEPEND_FLAG            = -MM
DEPEND_FILE            = Depend

GR_CFLAGS              =  -I${X11BASE}/include
GR_DFLAGS              = -DX11 -DXLIB -DX11HELP_PROG=\"${X11HELP_PROG}\"
GR_LIBS                = -L${X11BASE}/lib  -lX11
GR_SRCS                =  ${X11_SRCS}
GR_HELPER_SRCS         =  ${X11HELPER_SRCS}
GR_HELPER_PROG         =  ${X11HELP_PROG}

OBJS      = ${SRCS:.c=.o}
LIB_OBJS  = ${LIB_SRCS:.c=.o}
CLEANS    = ${OBJS} ${LIB_OBJS} lib${MODULE}.a lib${MODULE}.o ${MODULE}
