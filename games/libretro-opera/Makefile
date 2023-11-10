PORTNAME=	libretro-opera
DISTVERSION=	0.20230730
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3DO core for libretro
WWW=		https://github.com/libretro/opera-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	opera-libretro
GH_TAGNAME=	100ae1e7decefe1f17d98cfcb9f2af4ff8452691

PLIST_FILES=	lib/libretro/opera_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/opera_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
