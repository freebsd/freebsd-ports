PORTNAME=	libretro-quicknes
PORTVERSION=	0.20220228
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	NES emulator core for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	QuickNES_Core
GH_TAGNAME=	e6f08c1

PLIST_FILES=	lib/libretro/quicknes_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/quicknes_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
