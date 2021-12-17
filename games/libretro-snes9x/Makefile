PORTNAME=	libretro-snes9x
PORTVERSION=	0.20211024
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Snes9x - Portable Super Nintendo emulator

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
GH_TAGNAME=	73aa348

PLIST_FILES=	lib/libretro/snes9x_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
