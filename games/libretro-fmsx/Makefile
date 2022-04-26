PORTNAME=	libretro-fmsx
PORTVERSION=	0.20220309
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Port of fMSX to the libretro API

LICENSE=	FMSX
LICENSE_NAME=	FMSX
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fmsx-libretro
GH_TAGNAME=	f9ea9ea

PLIST_FILES=	lib/libretro/fmsx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/fmsx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
