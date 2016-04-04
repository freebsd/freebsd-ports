# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	default
PORTVERSION=	0.4.10.4
CATEGORIES=	games
PKGNAMEPREFIX=	freeminer-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Freeminer game engine

LICENSE=	LGPL21

RUN_DEPENDS=	freeminer:games/freeminer

USE_GITHUB=	yes
GH_ACCOUNT=	freeminer

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/freeminer/games/${PORTNAME}
PORTDATA=	*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
