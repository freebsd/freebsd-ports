# New ports collection makefile for:	xworm
# Version required:			1.02
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
CATEGORIES=	games
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	freebsd
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/XWorm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xworm
.for file in font grid raw
	@ ${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include <bsd.port.mk>
