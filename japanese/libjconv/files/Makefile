# $FreeBSD$

all:
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.lib
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.prog

install:
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.lib install
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.prog install

clean:
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.lib clean
	${MAKE} LOCALBASE=${LOCALBASE} -f Makefile.prog clean
