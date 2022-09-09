PORTNAME=	libretro-beetle_supergrafx
PORTVERSION=	0.20220218
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen supergrafx to libretro
WWW=		https://github.com/libretro/beetle-supergrafx-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-supergrafx-libretro
GH_TAGNAME=	59991a9

PLIST_FILES=	lib/libretro/mednafen_supergrafx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mednafen_supergrafx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
