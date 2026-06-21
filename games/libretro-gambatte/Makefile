PORTNAME=	libretro-gambatte
DISTVERSION=	0.20260515
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	Libretro Implementation of libgambatte, a Game Boy Color emulator
WWW=		https://github.com/libretro/gambatte-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gambatte-libretro
GH_TAGNAME=	3262c2aa4adae8dba4f6d51cdd931c15cb11569f
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/gambatte_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
