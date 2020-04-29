# $FreeBSD$

PORTNAME=	libretro-beetle_psx
PORTVERSION=	0.20200418
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
GH_TAGNAME=	dfab19a

PLIST_FILES=	libexec/libretro/mednafen_psx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
