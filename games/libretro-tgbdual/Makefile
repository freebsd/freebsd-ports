PORTNAME=	libretro-tgbdual
DISTVERSION=	0.20220806
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source GB/GBC emulator with game link support
WWW=		https://github.com/libretro/tgbdual-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	tgbdual-libretro
GH_TAGNAME=	a6f3018e6a23030afc1873845ee54d4b2d8ec9d3

PLIST_FILES=	lib/libretro/tgbdual_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/tgbdual_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
