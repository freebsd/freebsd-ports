PORTNAME=	libretro-beetle_psx
PORTVERSION=	0.20210128
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Standalone port/fork of Mednafen PSX to the Libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-psx-libretro
GH_TAGNAME=	3ec155d

PLIST_FILES=	lib/libretro/mednafen_psx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
