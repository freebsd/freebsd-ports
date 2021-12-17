PORTNAME=	libretro-snes9x2010
PORTVERSION=	0.20211102
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Snes9x - Portable Super Nintendo emulator (1.52)

# Commercial users must seek permission from copyright holders.
LICENSE=	PS
LICENSE_NAME=	PS
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	snes9x2010
GH_TAGNAME=	714b1c8

PLIST_FILES=	lib/libretro/snes9x2010_libretro.so

MAKE_ENV=	LTO=-flto  # may drop this branch on next port update

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/snes9x2010_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
