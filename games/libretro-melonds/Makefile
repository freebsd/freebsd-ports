PORTNAME=	libretro-melonds
PORTVERSION=	0.20220712
CATEGORIES=	games

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Port of melonDS to libretro
WWW=		https://github.com/libretro/melonDS/

LICENSE=	GPLv3

USES=		compiler:c++17-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	melonDS
GH_TAGNAME=	490a66a

PLIST_FILES=	lib/libretro/melonds_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/melonds_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
