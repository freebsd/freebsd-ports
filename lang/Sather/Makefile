# New ports collection makefile for:    Sather
# Version required:     1.0.1
# Date created:         Mon Oct 31 22:04:12 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.1.1.1 1994/11/01 06:08:02 hsu Exp $
#

DISTNAME=       Sather-1.0.2
MASTER_SITES=   ftp://ftp.icsi.berkeley.edu/pub/sather/
DISTFILES=      Sather-1.0.2.tar.Z
WRKSRC=		${WRKDIR}/Sather
ALL_TARGET=	testall

install:
	@if [ ! -e ${PREFIX}/bin ]; then mkdir -p ${PREFIX}/bin; fi
	@if [ ! -e ${PREFIX}/man/man1 ]; then mkdir -p ${PREFIX}/man/man1; fi
	install -c -m 555 ${WRKSRC}/Compiler/cs ${PREFIX}/bin
	install -c -m 555 ${WRKSRC}/Doc/man/man1/cs.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
