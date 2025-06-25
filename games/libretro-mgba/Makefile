PORTNAME=	libretro-mgba
DISTVERSION=	0.20250518
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Game Boy Advance Emulator for libretro
WWW=		https://github.com/libretro/mgba

LICENSE=	MPL20

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mgba
GH_TAGNAME=	c9bbf28b091c4c104485092279c7a6b114b2e8ff
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/mgba_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mgba_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
