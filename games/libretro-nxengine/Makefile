PORTNAME=	libretro-nxengine
PORTVERSION=	0.20220301
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cave Story game engine clone for libretro
WWW=		https://github.com/libretro/nxengine-libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib dos2unix gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	nxengine-libretro
GH_TAGNAME=	fc102fa

PLIST_FILES=	lib/libretro/nxengine_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/nxengine_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
