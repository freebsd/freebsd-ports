PORTNAME=	libretro-gpsp
DISTVERSION=	0.20231006
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gameboy emulator for libretro
WWW=		https://github.com/libretro/gpsp

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	gpsp
GH_TAGNAME=	eaf8b94702c5ded2fe3a3fc6a7f9718652fe8595

PLIST_FILES=	lib/libretro/gpsp_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/gpsp_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
