PORTNAME=	griels-quest
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Griel's Quest for the Sangraal
WWW=		https://github.com/nevat/griels-quest

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sdl
USE_GITHUB=	yes
GH_ACCOUNT=	nevat
USE_SDL=	sdl2 mixer2 image2

DATADIR=	${PREFIX}/share/griels

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/griels

.include <bsd.port.mk>
