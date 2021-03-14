# $FreeBSD$

PORTNAME=	libretro-mgba
PORTVERSION=	0.20210128
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Game Boy Advance Emulator for libretro

LICENSE=	MPL20

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mgba
GH_TAGNAME=	6186d45

PLIST_FILES=	lib/libretro/mgba_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mgba_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
