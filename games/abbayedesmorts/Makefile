# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abbayedesmorts
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of l'Abbaye des Morts by Locomalito

LICENSE=	GPLv3 CC-BY-3.0
LICENSE_COMB=	multi

USES=		sdl
USE_GITHUB=	yes
GH_ACCOUNT=	nevat
GH_PROJECT=	${PORTNAME}-gpl

PORTSCOUT=	skipv:v1.2,v1.13,v1.11 # git repo contains required portability fixes

USE_SDL=	sdl2 mixer2 image2

DATADIR=	${PREFIX}/share/abbayev2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/abbayev2

.include <bsd.port.mk>
