PORTNAME=	libretro-mednafen_pcfx
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen PCFX to libretro
WWW=		https://github.com/libretro/beetle-gba-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-pcfx-libretro
GH_TAGNAME=	47c355b6a515aef6dc57f57df1535570108a0e21

PLIST_FILES=	lib/libretro/mednafen_pcfx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_pcfx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
