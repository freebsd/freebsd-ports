# New ports collection makefile for:    mprof
# Version required:     3.0
# Date created:         Sat Nov  5 01:16:33 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.5 1995/04/24 11:01:33 asami Exp $
#

DISTNAME=       mprof-3.0
CATEGORIES+=	devel
MASTER_SITES=   ftp://cs.colorado.edu/pub/misc/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}
MAKEFILE=	Makefile.i386

do-install:
	install -c -s -m 555 ${WRKSRC}/mprof ${PREFIX}/bin
	install -c -m 555 ${WRKSRC}/libc_mp.a ${PREFIX}/lib
	install -c -m 555 ${WRKSRC}/mprof.1 ${PREFIX}/man/man1
	gzip -9nf ${PREFIX}/man/man1/mprof.1

.include <bsd.port.mk>
