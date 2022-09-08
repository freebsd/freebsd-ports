PORTNAME=	libretro-mgba
PORTVERSION=	0.20220211
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game Boy Advance Emulator for libretro
WWW=		https://github.com/libretro/mgba

LICENSE=	MPL20

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mgba
GH_TAGNAME=	5d48e07

PLIST_FILES=	lib/libretro/mgba_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mgba_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
