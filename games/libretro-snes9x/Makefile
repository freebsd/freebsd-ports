PORTNAME=	libretro-snes9x
DISTVERSION=	0.20241022
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Snes9x - Portable Super Nintendo emulator
WWW=		https://github.com/libretro/snes9x

# Commercial users must seek permission from copyright holders.
LICENSE=	PS
LICENSE_NAME=	PS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	snes9x
GH_TAGNAME=	49f484569ff2aec7ff08e7598a97d6c9e6eae72d
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/libretro

PLIST_FILES=	lib/libretro/snes9x_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
