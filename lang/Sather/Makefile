# New ports collection makefile for:    Sather
# Version required:     1.0.5
# Date created:         Mon Oct 31 22:04:12 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.10 1995/11/22 13:12:26 asami Exp $
#

DISTNAME=       Sather-1.0.5
PKGNAME=        sather-1.0.5
CATEGORIES+=	lang
MASTER_SITES=   ftp://ftp.icsi.berkeley.edu/pub/sather/

WRKSRC=		${WRKDIR}/Sather
ALL_TARGET=	testall

do-install:
	install -c -m 555 ${WRKSRC}/Compiler/cs ${PREFIX}/bin
	install -c -m 444 ${WRKSRC}/Doc/man/man1/cs.1 ${PREFIX}/man/man1
	-gzip -9nf ${PREFIX}/man/man1/cs.1
	mkdir -p ${PREFIX}/share/doc/sather
	install -c -m 444 ${WRKSRC}/Doc/License ${PREFIX}/share/doc/sather
.if !defined(NOPORTDOCS)
.for file in Bugs Changes Contributing FAQ README manual.ps
	install -c -m 444 ${WRKSRC}/Doc/${file} ${PREFIX}/share/doc/sather
.endfor
.endif

.include <bsd.port.mk>
