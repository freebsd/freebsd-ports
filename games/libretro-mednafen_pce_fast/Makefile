PORTNAME=	libretro-mednafen_pce_fast
DISTVERSION=	0.20231006
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen PCE Fast to libretro
WWW=		https://github.com/libretro/beetle-pce-fast-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-pce-fast-libretro
GH_TAGNAME=	1ce7a4a941b10aa0c2973cb441b89ee99e2c8d0e

PLIST_FILES=	lib/libretro/mednafen_pce_fast_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_pce_fast_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
