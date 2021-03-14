# $FreeBSD$

PORTNAME=	libretro-gpsp
PORTVERSION=	0.20210215
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Gameboy emulator for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gpsp
GH_TAGNAME=	300d0c0

PLIST_FILES=	lib/libretro/gpsp_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/gpsp_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
