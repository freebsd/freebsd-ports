# $FreeBSD$

PORTNAME=	libretro-beetle_ngp
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Standalone port of Mednafen NGP to the libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-ngp-libretro
GH_TAGNAME=	74cc0d8

PLIST_FILES=	lib/libretro/mednafen_ngp_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_ngp_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
