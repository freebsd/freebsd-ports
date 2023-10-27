PORTNAME=	libretro-mednafen_bsnes
PORTVERSION=	0.20220406
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen bSNES to libretro
WWW=		https://github.com/libretro/beetle-bsnes-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-bsnes-libretro
GH_TAGNAME=	d770563

PLIST_FILES=	lib/libretro/mednafen_snes_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_snes_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
