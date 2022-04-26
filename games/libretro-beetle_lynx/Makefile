PORTNAME=	libretro-beetle_lynx
PORTVERSION=	0.20220327
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Standalone port of Mednafen Lynx to libretro, itself a fork of Handy

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-lynx-libretro
GH_TAGNAME=	de0d520

PLIST_FILES=	lib/libretro/mednafen_lynx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_lynx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
