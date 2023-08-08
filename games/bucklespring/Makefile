PORTNAME=	bucklespring
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nostalgia bucklespring keyboard sound
WWW=		https://github.com/zevv/bucklespring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libalure.so:audio/alure

USES=		gmake openal pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	zevv
USE_XORG=	x11 xtst

MAKE_ENV+=	PATH_AUDIO=${DATADIR}/wav

ALL_TARGET=	buckle

LDFLAGS_i386=	-Wl,-znotext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/buckle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/wav
	${INSTALL_DATA} ${WRKSRC}/wav/* ${STAGEDIR}${DATADIR}/wav
	${INSTALL_DATA} ${WRKSRC}/buckle.desktop \
		${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
