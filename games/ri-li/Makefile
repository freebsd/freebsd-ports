PORTNAME=	Ri-li
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.5
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Drive a toy wood train in many levels - snake-like arcade game
WWW=		https://github.com/petitlapin/Li-Ri

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/SimpleIni.h:devel/simpleini

USES=		cmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	petitlapin
GH_PROJECT=	Li-Ri
USE_SDL=	sdl2 mixer2
CMAKE_ON=	USE_SYSTEM_SIMPLEINI
CMAKE_ARGS=	-DLIRI_DATA_DIR="${DATADIR}"

DATADIR=	${PREFIX}/share/Li-ri
PORTDATA=	*

.include <bsd.port.mk>
