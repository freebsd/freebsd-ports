PORTNAME=	libretro-genesis_plus_gx
DISTVERSION=	0.20231020
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced port of Genesis Plus
WWW=		https://github.com/libretro/Genesis-Plus-GX

# Commercial users must seek permission from copyright holders.
LICENSE=	GPGX
LICENSE_NAME=	GPGX
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	Genesis-Plus-GX
GH_TAGNAME=	3dc6af4b93b54ff524e7e93cc1407ad26c1f0340

PLIST_FILES=	lib/libretro/genesis_plus_gx_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/genesis_plus_gx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
