# New ports collection makefile for:    Sather
# Version required:     1.0.1
# Date created:         Mon Oct 31 22:04:12 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.8 1995/04/16 21:28:20 asami Exp $
#

DISTNAME=       Sather-1.0.5
CATEGORIES+=	languages
MASTER_SITES=   ftp://ftp.icsi.berkeley.edu/pub/sather/

WRKSRC=		${WRKDIR}/Sather
ALL_TARGET=	testall

do-install:
	install -c -m 555 ${WRKSRC}/Compiler/cs ${PREFIX}/bin
	install -c -m 555 ${WRKSRC}/Doc/man/man1/cs.1 ${PREFIX}/man/man1
	-gzip -9nf ${PREFIX}/man/man1/cs.1

.include <bsd.port.mk>
