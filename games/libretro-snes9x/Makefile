PORTNAME=	libretro-snes9x
DISTVERSION=	0.20231013
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Snes9x - Portable Super Nintendo emulator
WWW=		https://github.com/libretro/snes9x

# Commercial users must seek permission from copyright holders.
LICENSE=	PS
LICENSE_NAME=	PS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	snes9x
GH_TAGNAME=	ec4ebfc8f3819a9522fcb8e53eed985090017b1b

PLIST_FILES=	lib/libretro/snes9x_libretro.so

BUILD_WRKSRC=	${WRKSRC}/libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
