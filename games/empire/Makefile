# New ports collection makefile for:	empire
# Version required:			1.1
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		empire
PKGNAME=		empire-1.1
CATEGORIES=		games
MASTER_SITES=		ftp://locke.ccil.org/pub/esr/

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/empire-1.1
MAN6=			empire.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/empire ${PREFIX}/bin/empire
	@ ${INSTALL_MAN} ${WRKSRC}/empire.6 ${PREFIX}/man/man6
	@ ${MKDIR} ${PREFIX}/share/doc/empire
.for file in BUGS COPYING READ.ME
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/empire/${file}
.endfor

.include <bsd.port.mk>
