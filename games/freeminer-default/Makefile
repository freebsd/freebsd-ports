PORTNAME=	default
PORTVERSION=	0.4.10.4
CATEGORIES=	games
PKGNAMEPREFIX=	freeminer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The main game for the Freeminer game engine
WWW=		https://freeminer.org/

LICENSE=	LGPL21

DEPRECATED=	depends on deprecated games/freeminer
EXPIRATION_DATE=	2026-01-31

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
