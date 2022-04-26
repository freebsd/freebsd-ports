PORTNAME=	libretro-handy
PORTVERSION=	0.20220215
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Atari Lynx emulator Handy for Libretro

LICENSE=	ZLIB

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	5145f79

PLIST_FILES=	lib/libretro/handy_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/handy_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;
	
.include <bsd.port.mk>
