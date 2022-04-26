PORTNAME=	libretro-prboom
PORTVERSION=	0.20220327
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Port of prboom to libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	b22a6b1

PLIST_FILES=	lib/libretro/prboom_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/prboom_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
