PORTNAME=	libretro-cap32
PORTVERSION=	0.20220402
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amstrad CPC computers emulator core for libretro API
WWW=		https://github.com/libretro/libretro-cap32

LICENSE=	GPLv2

USES=		compiler:c++11-lang gmake localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	a1b2329

PLIST_FILES=	lib/libretro/cap32_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/cap32_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
