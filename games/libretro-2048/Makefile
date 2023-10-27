PORTNAME=	libretro-2048
DISTVERSION=	0.20230220
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of 2048 puzzle game to the libretro API
WWW=		https://github.com/libretro/libretro-2048

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	331c1de588ed8f8c370dcbc488e5434a3c09f0f2

PLIST_FILES=	lib/libretro/2048_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/2048_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
