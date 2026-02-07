PORTNAME=	libretro-mednafen_ngp
DISTVERSION=	0.20230220
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone port of Mednafen NGP to the libretro API
WWW=		https://github.com/libretro/beetle-ngp-libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-ngp-libretro
GH_TAGNAME=	65460e3a9ad529f6901caf669abbda11f437ab55

PLIST_FILES=	lib/libretro/mednafen_ngp_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/mednafen_ngp_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
