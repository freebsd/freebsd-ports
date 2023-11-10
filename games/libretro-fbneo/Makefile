PORTNAME=	libretro-fbneo
DISTVERSION=	0.20231025
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Final Burn Alpha fork for libretro
WWW=		https://github.com/libretro/FBNeo

LICENSE=	FBNeo
LICENSE_NAME=	FBNeo
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c11 gmake

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FBNeo
GH_TAGNAME=	6f65c17648bb98217d8ddcdc750505d4ac0916e5

USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/src/burner/libretro

PLIST_FILES=	lib/libretro/fbneo_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/src/burner/libretro/fbneo_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
