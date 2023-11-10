PORTNAME=	libretro-gambatte
DISTVERSION=	0.20230929
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretro Implementation of libgambatte, a Game Boy Color emulator
WWW=		https://github.com/libretro/gambatte-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gambatte-libretro
GH_TAGNAME=	40d0d7ac4e11b5c2d1feac2ce96e4d824c248985

PLIST_FILES=	lib/libretro/gambatte_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
