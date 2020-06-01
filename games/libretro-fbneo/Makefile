# $FreeBSD$

PORTNAME=	libretro-fbneo
PORTVERSION=	0.20200504
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Final Burn Alpha fork for libretro

LICENSE=	FBNeo
LICENSE_NAME=	FBNeo
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=  dist-mirror pkg-mirror auto-accept

USES=		gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

BUILD_DEPEND=	devel/nasm

PLIST_FILES=	lib/libretro/fbneo_libretro.so

NO_CDROM=       Commercial users must seek permission from copyright holders.

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	FBNeo
GH_TAGNAME=	09cff81

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/src/burner/libretro/fbneo_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
