PORTNAME=	libretro-cap32
DISTVERSION=	0.20230712
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amstrad CPC computers emulator core for libretro API
WWW=		https://github.com/libretro/libretro-cap32

LICENSE=	GPLv2

USES=		compiler:c++11-lang gmake localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	4a071f2c004273abf0f9fa0640b36f6664d8381a

PLIST_FILES=	lib/libretro/cap32_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/cap32_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
