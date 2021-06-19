PORTNAME=	libretro-tyrquake
PORTVERSION=	0.20210214
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro port of Tyrquake (Quake 1 engine)

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	tyrquake
GH_TAGNAME=	e76477d

PLIST_FILES=	lib/libretro/tyrquake_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
