PORTNAME=	libretro-boom3
DISTVERSION=	0.20220810
CATEGORIES=	games

MAINTAINER=	sdalu@sdalu.com
COMMENT=	dhewm3 (Doom 3) core for libretro API
WWW=		https://github.com/libretro/boom3

LICENSE=	GPLv3

USES=		gmake gl localbase:ldflags
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	boom3
GH_TAGNAME=	0bea79abf5ec8262dfe9af73cb8c54ea6e2aeb98

WRKSRC_SUBDIR=	neo

PLIST_FILES=	lib/libretro/boom3_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/boom3_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
