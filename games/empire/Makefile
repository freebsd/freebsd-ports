# New ports collection makefile for:	empire
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	empire
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	ftp://locke.ccil.org/pub/esr/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}
MAN6=		empire.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/empire ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/empire.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
.for file in BUGS READ.ME
	@${MKDIR} ${PREFIX}/share/doc/empire
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/empire
.endfor
.endif

.include <bsd.port.mk>
