PORTNAME=	libretro-hatari
PORTVERSION=	0.20220327
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Atari ST/STE/TT/Falcon emulator

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	hatari
GH_TAGNAME=	e5e36a5

PLIST_FILES=	lib/libretro/hatari_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/hatari_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
