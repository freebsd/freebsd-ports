PORTNAME=	libretro-snes9x2005
DISTVERSION=	1.34-409
DISTVERSIONSUFFIX=	-gfd45b0e
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Snes9x - Portable Super Nintendo emulator (1.43)
WWW=		https://github.com/libretro/snes9x2005

# Commercial users must seek permission from copyright holders.
LICENSE=	PS
LICENSE_NAME=	PS
LICENSE_FILE=	${WRKSRC}/copyright
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	snes9x2005

PLIST_FILES=	lib/libretro/snes9x2005_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
