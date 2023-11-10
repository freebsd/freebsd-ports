PORTNAME=	libretro-handy
DISTVERSION=	0.20230819
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari Lynx emulator Handy for Libretro
WWW=		https://github.com/libretro/libretro-handy

LICENSE=	ZLIB

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	0559d3397f689ea453b986311aeac8dbd33afb0b

PLIST_FILES=	lib/libretro/handy_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/handy_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
