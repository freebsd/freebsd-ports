# $FreeBSD$

PORTNAME=	libretro-px68k
PORTVERSION=	0.20200527
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	SHARP X68000 libretro core

LICENSE=	GPLv2

USES=		compiler:gcc-c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	px68k-libretro
GH_TAGNAME=	415dd30

PLIST_FILES=	lib/libretro/px68k_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/px68k_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
