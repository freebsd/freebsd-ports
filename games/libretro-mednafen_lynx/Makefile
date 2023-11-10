PORTNAME=	libretro-mednafen_lynx
DISTVERSION=	0.20230721
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen Lynx to libretro, itself a fork of Handy
WWW=		https://github.com/libretro/beetle-lynx-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-lynx-libretro
GH_TAGNAME=	fab3ac02d5622eb53a707bd392cc037282e9d8b4

PLIST_FILES=	lib/libretro/mednafen_lynx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_lynx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
