PORTNAME=	libretro-nestopia
DISTVERSION=	0.20260228
CATEGORIES=	games

MAINTAINER=	tilde@ultros.pro
COMMENT=	NEStopia emulator for libretro
WWW=		https://github.com/libretro/nestopia

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	nestopia
GH_TAGNAME=	c0ae3bcbe78a1a21a20384b96b70774cc165d2c2
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/libretro

PLIST_FILES=	lib/libretro/nestopia_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
