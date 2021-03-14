# $FreeBSD$

PORTNAME=	libretro-beetle_gba
PORTVERSION=	0.20210131
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Standalone port of Mednafen GBA to libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-gba-libretro
GH_TAGNAME=	8d1e421

PLIST_FILES=	lib/libretro/mednafen_gba_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_gba_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
