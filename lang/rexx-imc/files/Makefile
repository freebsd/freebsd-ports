# Makefile for REXX/imc
#
# Based upon the original by the author
# Heavily hacked by jfitz@FreeBSD.ORG
#

CC=		gcc
PIC=		-fPIC
CCFLAGS=	-DHAS_TTYCOM -D_REQUIRED -c ${PIC}

OPTFLAGS=	-O2

# Release Date Variables
RXDAY=		1
RXMONTH=	8
RXYEAR=		96
DATE=		-DDAY=${RXDAY} -DMONTH=${RXMONTH} -DYEAR=${RXYEAR}

# Shared Library Version
VER=		1.6.4

SHAREDLIB=	librexx.so.${VER}
STATICLIB=	librexx.a
.ifdef(BUILD_STATIC)
REXXLIB=${STATICLIB}
.else
REXXLIB=${SHAREDLIB}
.endif
MATH=		rxmathfn.rxfn
REXXIMC=	${PREFIX}/bin
FILEDEFS=	-DREXXIMC=\"${REXXIMC}\"
LIBFILES=	rexx.o rxfn.o calc.o util.o shell.o interface.o globals.o
HFILES=		const.h globals.h functions.h rexxsaa.h

all:		rexx rxque rxstack ${MATH}

interface.o:	interface.c ${HFILES}
		${CC} ${OPTFLAGS} ${CCFLAGS} -c ${DATE} ${FILEDEFS} -o $@ interface.c

${SHAREDLIB}:	${LIBFILES}
		${LD} -Bshareable -o ${SHAREDLIB} ${LIBFILES}

${STATICLIB}:	${LIBFILES}
		ar rc ${STATICLIB} ${LIBFILES}
		${RANLIB} ${STATICLIB}

rexx:		main.o ${REXXLIB}
		${CC} ${OPTFLAGS} -o rexx main.o -L. -lrexx

rxque:		rxque.o ${STATICLIB}
		${CC} ${OPTFLAGS} -o rxque rxque.o

rxstack:	rxstack.o ${STATICLIB}
		${CC} ${OPTFLAGS} -o rxstack rxstack.o

rxmathfn.rxfn:	rxmathfn.o ${HFILES}
		${LD} -Bshareable -o rxmathfn.rxfn rxmathfn.o -lm

interface.o:	interface.c ${HFILES}
		${CC} ${OPTFLAGS} ${CCFLAGS} -o interface.o ${FILEDEFS} interface.c

.c.o:
		${CC} ${OPTFLAGS} ${CCFLAGS} -o $@ $<
