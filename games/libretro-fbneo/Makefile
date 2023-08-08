PORTNAME=	libretro-fbneo
PORTVERSION=	0.20220925
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Final Burn Alpha fork for libretro
WWW=		https://github.com/libretro/FBNeo

LICENSE=	FBNeo
LICENSE_NAME=	FBNeo
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c11 gmake gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FBNeo
GH_TAGNAME=	8678b0f

USE_GL=		gl
USE_LDCONFIG=	yes

MAKEFILE=	Makefile.freebsd

PLIST_FILES=	lib/libretro/fbneo_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/src/burner/libretro/fbneo_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
