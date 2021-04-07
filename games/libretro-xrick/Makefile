PORTNAME=	libretro-xrick
PORTVERSION=	0.20201218
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro implementation of "Rick Dangerous"

LICENSE=	GPLv2

USES=		gmake localbase sdl dos2unix
USE_SDL=	sdl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	xrick-libretro
GH_TAGNAME=	0aad6c6

MAKEFILE=	Makefile.libretro
DOS2UNIX_FILES=	${MAKEFILE}

PLIST_FILES=	lib/libretro/xrick_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/xrick_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
