# New ports collection makefile for:    mprof
# Version required:     3.0
# Date created:         Sat Nov  5 01:16:33 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.7 1996/10/18 08:38:18 max Exp $
#

DISTNAME=       mprof-3.0
CATEGORIES=	devel
MASTER_SITES=   ftp://cs.colorado.edu/pub/misc/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}
MAKEFILE=	Makefile.i386
MAN1=		mprof.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprof ${PREFIX}/bin
	install -c -m 555 ${WRKSRC}/libc_mp.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/mprof.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
