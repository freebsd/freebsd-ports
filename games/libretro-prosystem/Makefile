PORTNAME=	libretro-prosystem
PORTVERSION=	0.20220228
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of ProSystem to the libretro API
WWW=		https://github.com/libretro/prosystem-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	prosystem-libretro
GH_TAGNAME=	fbf62c3

PLIST_FILES=	lib/libretro/prosystem_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
