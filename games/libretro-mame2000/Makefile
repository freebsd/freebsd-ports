PORTNAME=	libretro-mame2000
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	MAME (0.37b5) for libretro

LICENSE=	GPLv2

BROKEN_aarch64=	fails to build: src/libretro/libretro-common/libco/aarch64.c:25:1: error: meaningless 'volatile' on asm outside function

USES=		compiler:c++11-lib dos2unix gmake
DOS2UNIX_FILES=	src/cpu/tms9900/99xxstat.h
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2000-libretro
GH_TAGNAME=	e364a15

PLIST_FILES=	lib/libretro/mame2000_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mame2000_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
