PORTNAME=	libretro-nestopia
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NEStopia emulator for libretro
WWW=		https://github.com/libretro/nestopia

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	nestopia
GH_TAGNAME=	3dcbec4682e079312d6943e1357487645ec608c7

PLIST_FILES=	lib/libretro/nestopia_libretro.so

BUILD_WRKSRC=	${WRKSRC}/libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
