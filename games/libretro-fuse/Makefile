PORTNAME=	libretro-fuse
PORTVERSION=	0.20220213
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Port of the Fuse Unix Spectrum Emulator to libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fuse-libretro
GH_TAGNAME=	042f8a9

PLIST_FILES=	lib/libretro/fuse_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/fuse_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
