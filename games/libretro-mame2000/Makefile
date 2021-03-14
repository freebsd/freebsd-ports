# $FreeBSD$

PORTNAME=	libretro-mame2000
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	MAME (0.37b5) for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2000-libretro
GH_TAGNAME=	e364a15

PLIST_FILES=	lib/libretro/mame2000_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mame2000_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
