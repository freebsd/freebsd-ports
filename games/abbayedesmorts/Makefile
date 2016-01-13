# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abbayedesmorts
PORTVERSION=	git20150512
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of l'Abbaye des Morts by Locomalito

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	nevat
GH_PROJECT=	abbayedesmorts-gpl
GH_TAGNAME=	558116d5d6

PORTSCOUT=	skipv:v1.2,v1.13,v1.11 # git repo contains required portability fixes

USE_SDL=	sdl2 mixer2 image2

DATADIR=	${PREFIX}/share/abbayev2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/abbayev2

.include <bsd.port.mk>
