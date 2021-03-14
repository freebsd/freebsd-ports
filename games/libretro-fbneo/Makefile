# $FreeBSD$

PORTNAME=	libretro-fbneo
PORTVERSION=	0.20210218
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Final Burn Alpha fork for libretro

LICENSE=	FBNeo
LICENSE_NAME=	FBNeo
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c11 gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

PLIST_FILES=	lib/libretro/fbneo_libretro.so

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FBNeo
GH_TAGNAME=	a6d552b

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/src/burner/libretro/fbneo_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
