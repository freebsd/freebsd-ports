# $FreeBSD$

PORTNAME=	libretro-bluemsx
PORTVERSION=	0.20200504
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Port of blueMSX to the libretro API

LICENSE=	GPLv3

BROKEN_aarch64=	error: constant expression evaluates to -1 which cannot be narrowed to type 'char' [-Wc++11-narrowing]

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	blueMSX-libretro
GH_TAGNAME=	7a1d40e

PLIST_FILES=	lib/libretro/bluemsx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/bluemsx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
