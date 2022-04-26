PORTNAME=	libretro-o2em
PORTVERSION=	0.20220327
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Port of O2EM to the libretro API, an Odyssey 2 / VideoPac emulator

LICENSE=	ART20

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	efd749c

PLIST_FILES=	lib/libretro/o2em_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/o2em_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
