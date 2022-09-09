PORTNAME=	libretro-xrick
PORTVERSION=	0.20220331
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretro implementation of "Rick Dangerous"
WWW=		https://github.com/libretro/xrick-libretro

LICENSE=	GPLv2

USES=		gmake localbase sdl
USE_SDL=	sdl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	xrick-libretro
GH_TAGNAME=	10d7318

MAKEFILE=	Makefile.freebsd
DOS2UNIX_FILES=	${MAKEFILE}

PLIST_FILES=	lib/libretro/xrick_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/xrick_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
