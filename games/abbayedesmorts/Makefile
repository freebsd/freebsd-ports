# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abbayedesmorts
PORTVERSION=	git20150409
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of l'Abbaye des Morts by Locomalito

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3 # portability changes not yet merged upstream
GH_PROJECT=	abbayedesmorts-gpl
GH_TAGNAME=	c603c83

USE_SDL=	sdl2 mixer2 image2

DATADIR=	${PREFIX}/share/abbayev2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/abbayev2

.include <bsd.port.mk>
