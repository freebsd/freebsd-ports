# $FreeBSD$

PORTNAME=	libretro-nxengine
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	NXEngine is a Cave Story game engine clone for libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib dos2unix gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	nxengine-libretro
GH_TAGNAME=	f39250e

PLIST_FILES=	libexec/libretro/nxengine_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
