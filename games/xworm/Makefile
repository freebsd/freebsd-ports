# New ports collection makefile for:	xworm
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xworm
PORTVERSION=	1.02
CATEGORIES=	games
MASTER_SITES=	http://www.ekran.no/archive/x/
DISTNAME=	${PORTNAME}102

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/XWorm
USE_X_PREFIX=	yes
ALL_TARGET=	freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include <bsd.port.mk>
