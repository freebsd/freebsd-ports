PORTNAME=	libretro-gambatte
DISTVERSION=	0.20241022
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Libretro Implementation of libgambatte, a Game Boy Color emulator
WWW=		https://github.com/libretro/gambatte-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gambatte-libretro
GH_TAGNAME=	a1c4c98582308afafd73c050167a7ea330469e98
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/gambatte_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
