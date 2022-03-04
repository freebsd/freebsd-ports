PORTNAME=	libretro-px68k
PORTVERSION=	0.20210113
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	SHARP X68000 libretro core

LICENSE=	GPLv2

USES=		compiler:gcc-c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	px68k-libretro
GH_TAGNAME=	8455d9c

PLIST_FILES=	lib/libretro/px68k_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/px68k_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
