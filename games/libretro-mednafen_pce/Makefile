PORTNAME=	libretro-mednafen_pce
DISTVERSION=	0.20231006
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen PCE to libretro
WWW=		https://github.com/libretro/beetle-pce-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-pce-libretro
GH_TAGNAME=	b59e34af5383fdfe626af5900bbb231871ece0ea

PLIST_FILES=	lib/libretro/mednafen_pce_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_pce_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
