# $FreeBSD$

PORTNAME=	libretro-handy
PORTVERSION=	0.20200504
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Atari Lynx emulator Handy for Libretro

LICENSE=	ZLIB

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	c9fe65d

PLIST_FILES=	lib/libretro/handy_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/handy_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;
	
.include <bsd.port.mk>
