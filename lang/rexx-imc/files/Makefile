# Makefile for REXX/imc-1.6?
#
# Based upon the original by the author
# Heavily hacked by jfitz@FreeBSD.ORG
#

CC?=		gcc
PIC=		-fPIC
CCFLAGS=	-DHAS_TTYCOM -D_REQUIRED -DRENAME_UNDELETE -c ${PIC}

OPTFLAGS=	-O2

# Release Date Variables
RXDAY=		1
RXMONTH=	8
RXYEAR=		96
DATE=		-DDAY=${RXDAY} -DMONTH=${RXMONTH} -DYEAR=${RXYEAR}

REXXDOCS=	README README.bugreport README.docs \
		README.files README.make README.news README.platforms \
		rexx.info rexx.ref rexx.summary rexx.tech

# Shared Library Version
.if ${PORTOBJFORMAT} == "elf"
VER=		2
SHAREDLIB=	librexx.so librexx.so.${VER}
.else
VER=		2.0
SHAREDLIB=	librexx.so.${VER}
.endif
STATICLIB=	librexx.a

REXXLIB=${STATICLIB} ${SHAREDLIB}

MATH=		rxmathfn.rxfn
REXXIMC=	${PREFIX}/bin
FILEDEFS=	-DREXXIMC=\"${REXXIMC}\"
LIBFILES=	rexx.o rxfn.o calc.o util.o shell.o interface.o globals.o
HFILES=		const.h globals.h functions.h rexxsaa.h

all:		rexx rxque rxstack ${MATH} rexx.1

interface.o:	interface.c ${HFILES}
		${CC} ${OPTFLAGS} ${CCFLAGS} -c ${DATE} ${FILEDEFS} -o $@ interface.c

${SHAREDLIB}:	${LIBFILES}
.for t in ${.TARGET}
		${LD} -Bshareable -o ${t} ${LIBFILES}
.endfor

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

rexx.1: rexx.1.in
		sed -e "s|@REXXLIBDIR@|${PREFIX}/bin|" rexx.1.in > rexx.1

install:
		@strip ${SHAREDLIBS} rxmathfn.rxfn
.for f in rexx rxque rxstack
		${BSD_INSTALL_PROGRAM} ${f} ${PREFIX}/bin
.endfor
.for f in rxmathfn.rxfn rxmathfn.rxlib
		${BSD_INSTALL_DATA} ${f} ${PREFIX}/bin
.endfor
.for f in ${REXXLIB}
		${BSD_INSTALL_DATA} ${f} ${PREFIX}/lib
.endfor
		${BSD_INSTALL_DATA} rexxsaa.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/rexx-imc/
.for f in ${REXXDOCS}
		${BSD_INSTALL_DATA} ${f} ${PREFIX}/share/doc/rexx-imc/
.endfor
		${BSD_INSTALL_DATA} rexx.1 ${PREFIX}/man/man1
.endif

.c.o:
		${CC} ${OPTFLAGS} ${CCFLAGS} -o $@ $<
