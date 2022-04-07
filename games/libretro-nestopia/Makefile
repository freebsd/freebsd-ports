PORTNAME=	libretro-nestopia
PORTVERSION=	0.20220322
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	NEStopia emulator for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	nestopia
GH_TAGNAME=	7dbd5c6

PLIST_FILES=	lib/libretro/nestopia_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
