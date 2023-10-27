PORTNAME=	libretro-quicknes
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NES emulator core for libretro
WWW=		https://github.com/libretro/QuickNES_Core

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	QuickNES_Core
GH_TAGNAME=	058d66516ed3f1260b69e5b71cd454eb7e9234a3

PLIST_FILES=	lib/libretro/quicknes_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/quicknes_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
