# $FreeBSD$

PREFIX?=	/usr/local
LOCALBASE?=	/usr/local

MAKE_ARGS=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

all:
	${MAKE} ${MAKE_ARGS} -f Makefile.lib
	${MAKE} ${MAKE_ARGS} -f Makefile.prog

install:
	${MAKE} ${MAKE_ARGS} -f Makefile.lib install
	${MAKE} ${MAKE_ARGS} -f Makefile.prog install

clean:
	${MAKE} ${MAKE_ARGS} -f Makefile.lib clean
	${MAKE} ${MAKE_ARGS} -f Makefile.prog clean
