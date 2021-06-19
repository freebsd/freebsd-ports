PORTNAME=	libretro-vecx
PORTVERSION=	0.20210214
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Vectrex emulator for libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake localbase gl
USE_GL+=	gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	9af0702

PLIST_FILES=	lib/libretro/vecx_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
