PORTNAME=	libretro-freeintv
PORTVERSION=	0.20210512
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Libretro emulation core for the Mattel Intellivision

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FreeIntv
GH_TAGNAME=	5fc8d85

PLIST_FILES=	lib/libretro/freeintv_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/freeintv_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
