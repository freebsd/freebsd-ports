# New ports collection makefile for:	gofer
# Version required:     2.30
# Date created:         Wed Feb  1 01:51:59 PST 1995
# Whom:                 hsu
#
# $Id$
#

DISTNAME =	gofer230a
MASTER_SITES =	ftp://cs.nott.ac.uk/nott-fp/languages/haskell/gofer/
WRKSRC = ${WRKDIR}/src
LIBDIR = ${PREFIX}/lib/Gofer

install:
	-mkdir -p ${LIBDIR}
	-mkdir -p ${PREFIX}/man/man1
	-mkdir -p ${PREFIX}/bin
	install -c -m 444 ${WRKDIR}/*.prelude ${LIBDIR}
	install -c -m 444 ${WRKDIR}/src/prelude.h ${LIBDIR}
	install -c -m 444 ${WRKDIR}/src/gofc.h ${LIBDIR}
	perl -pi -e "s|#include \"prelude.h\"|#include \"${LIBDIR}/prelude.h\"|" ${LIBDIR}/gofc.h
	install -c -m 444 ${WRKDIR}/src/runtime.o ${LIBDIR}
	install -c -m 555 ${WRKDIR}/scripts/gofer ${PREFIX}/bin
	install -c -m 555 ${WRKDIR}/scripts/goferc ${PREFIX}/bin
	install -c -m 555 ${WRKDIR}/src/gofer ${LIBDIR}
	install -c -m 555 ${WRKDIR}/src/gofc ${LIBDIR}
	install -c -m 444 ${WRKDIR}/docs/gofer.1 ${PREFIX}/man/man1
	-rm -f ${PREFIX}/man/man1/gofer.1.gz
	gzip -9 ${PREFIX}/man/man1/gofer.1
	-mkdir -p ${LIBDIR}/docs
	install -c -m 444 ${WRKDIR}/docs/* ${LIBDIR}/docs

.include <bsd.port.mk>
