PORTNAME=	libretro-a5200
PORTVERSION=	0.20220113
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Port of Atari 5200 emulator for GCW0

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	a5200
GH_TAGNAME=	20c92c9bb159ddb9cc80afb66ad67148c995f7a1

USE_LDCONFIG=	yes
PLIST_FILES=	lib/libretro/a5200_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/a5200_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
