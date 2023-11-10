PORTNAME=	libretro-hatari
DISTVERSION=	0.20230929
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari ST/STE/TT/Falcon emulator
WWW=		https://github.com/libretro/hatari

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	hatari
GH_TAGNAME=	a4c9eb0bb79e47a2870c12b04566c1f8d25e4bf3

PLIST_FILES=	lib/libretro/hatari_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/hatari_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
