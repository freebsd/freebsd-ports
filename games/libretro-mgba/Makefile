PORTNAME=	libretro-mgba
DISTVERSION=	0.20250724
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Game Boy Advance Emulator for libretro
WWW=		https://github.com/libretro/mgba

LICENSE=	MPL20

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mgba
GH_TAGNAME=	affc86e4c07b6e1e8363e0bc1c5ffb813a2e32c9
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/mgba_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mgba_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
