PORTNAME=	libretro-tyrquake
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretro port of Tyrquake (Quake 1 engine)
WWW=		https://github.com/libretro/tyrquake

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	tyrquake
GH_TAGNAME=	77217664a09afe893a06be8e3e8f9611184636f8

PLIST_FILES=	lib/libretro/tyrquake_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
