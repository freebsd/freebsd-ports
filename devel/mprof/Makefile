# New ports collection makefile for:    mprof
# Version required:     3.0
# Date created:         Sat Nov  5 01:16:33 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.1.1.1 1994/11/05 09:56:05 hsu Exp $
#

DISTNAME=       mprof-3.0
MASTER_SITES=   ftp://cs.colorado.edu/pub/misc/
EXTRACT_SUFX=	.tar.Z
WRKSRC=		${WRKDIR}
MAKEFILE=	Makefile.i386

install:
	@if [ ! -e ${PREFIX}/bin ]; then mkdir -p ${PREFIX}/bin; fi
	@if [ ! -e ${PREFIX}/lib ]; then mkdir -p ${PREFIX}/lib; fi
	@if [ ! -e ${PREFIX}/man/man1 ]; then mkdir -p ${PREFIX}/man/man1; fi
	install -c -m 555 ${WRKSRC}/mprof ${PREFIX}/bin
	install -c -m 555 ${WRKSRC}/libc_mp.a ${PREFIX}/lib
	install -c -m 555 ${WRKSRC}/mprof.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
