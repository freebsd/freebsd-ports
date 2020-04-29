# $FreeBSD$

PORTNAME=	libretro-genesis_plus_gx
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Enhanced port of Genesis Plus

LICENSE=	GPGX
LICENSE_NAME=	GPGX
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=  dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

NO_CDROM=       Commercial users must seek permission from copyright holders.

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	Genesis-Plus-GX
GH_TAGNAME=	5055106

PLIST_FILES=	libexec/libretro/genesis_plus_gx_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
