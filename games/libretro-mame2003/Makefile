PORTNAME=	libretro-mame2003
DISTVERSION=	0.20231017
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MAME 0.78 for libretro
WWW=		https://github.com/libretro/mame2003-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame2003-libretro
GH_TAGNAME=	55999949bf7d132df117b736f3434382a0d4ab9f

PLIST_FILES=	lib/libretro/mame2003_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mame2003_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
