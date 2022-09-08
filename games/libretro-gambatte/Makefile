PORTNAME=	libretro-gambatte
PORTVERSION=	0.20220325
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
GH_TAGNAME=	1553621

PLIST_FILES=	lib/libretro/gambatte_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
