# Created by: Timothy Beyer <beyert@cs.ucr.edu>

PORTNAME=	libretro-bsnes
PORTVERSION=	20211218
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Standalone port of bSNES to libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake

USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	bsnes-libretro
GH_TAGNAME=	9549275

USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/bsnes_libretro.so

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/bsnes_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
