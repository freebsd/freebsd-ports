PORTNAME=	libretro-a5200
DISTVERSION=	0.20230817
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Atari 5200 emulator for GCW0
WWW=		https://github.com/libretro/a5200

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	a5200
GH_TAGNAME=	0942c88d64cad6853b539f51b39060a9de0cbcab

USE_LDCONFIG=	yes
PLIST_FILES=	lib/libretro/a5200_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/a5200_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
