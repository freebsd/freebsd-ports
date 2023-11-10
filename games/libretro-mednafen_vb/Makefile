PORTNAME=	libretro-mednafen_vb
DISTVERSION=	0.20230528
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen VB to libretro
WWW=		https://github.com/libretro/beetle-vb-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-vb-libretro
GH_TAGNAME=	732a8f701e671bf032165730fdf8bd96fb5ca7bb

PLIST_FILES=	lib/libretro/mednafen_vb_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_vb_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
