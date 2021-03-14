# $FreeBSD$

PORTNAME=	libretro-gw
PORTVERSION=	0.20210129
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro core for Game & Watch simulators

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gw-libretro
GH_TAGNAME=	2be30ba

PLIST_FILES=	lib/libretro/gw_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/gw_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
