PORTNAME=	abbayedesmorts
PORTVERSION=	2.0.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of l'Abbaye des Morts by Locomalito
WWW=		https://locomalito.com/abbaye_des_morts.php \
		https://github.com/nevat/abbayedesmorts-gpl

LICENSE=	GPLv3 CC-BY-3.0
LICENSE_COMB=	multi

USES=		gmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	nevat
GH_PROJECT=	${PORTNAME}-gpl
USE_SDL=	sdl2 mixer2 image2

PORTSCOUT=	skipv:v1.2,v1.13,v1.11 # git repo contains required portability fixes

DATADIR=	${PREFIX}/share/abbayev2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/abbayev2

.include <bsd.port.mk>
