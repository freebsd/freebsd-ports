PORTNAME=	libretro-px68k
DISTVERSION=	0.20230114
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SHARP X68000 libretro core
WWW=		https://github.com/libretro/px68k-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	px68k-libretro
GH_TAGNAME=	4c7542e34df71e3ebab77b5867901747d58dbb38

PLIST_FILES=	lib/libretro/px68k_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/px68k_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
