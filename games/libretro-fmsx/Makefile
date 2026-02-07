PORTNAME=	libretro-fmsx
DISTVERSION=	0.20230417
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of fMSX to the libretro API
WWW=		https://github.com/libretro/fmsx-libretro

LICENSE=	FMSX
LICENSE_NAME=	FMSX
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fmsx-libretro
GH_TAGNAME=	1806eed4376fbe2fad82fa19271ea298cfbb7795

PLIST_FILES=	lib/libretro/fmsx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/fmsx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
