# New ports collection makefile for:    Sather
# Version required:     1.0.5
# Date created:         Mon Oct 31 22:04:12 PST 1994
# Whom:                 hsu
#
# $Id: Makefile,v 1.11 1996/03/07 13:00:53 asami Exp $
#

DISTNAME=       Sather-1.0.5
PKGNAME=        sather-1.0.5
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.icsi.berkeley.edu/pub/sather/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/Sather
ALL_TARGET=	testall

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Compiler/cs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/cs.1 ${PREFIX}/man/man1
	-gzip -9nf ${PREFIX}/man/man1/cs.1
	${MKDIR} ${PREFIX}/share/doc/sather
	${INSTALL_DATA} ${WRKSRC}/Doc/License ${PREFIX}/share/doc/sather
.if !defined(NOPORTDOCS)
.for file in Bugs Changes Contributing FAQ README manual.ps
	${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${PREFIX}/share/doc/sather
.endfor
.endif

.include <bsd.port.mk>
