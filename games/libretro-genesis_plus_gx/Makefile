# $FreeBSD$

PORTNAME=	libretro-genesis_plus_gx
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Enhanced port of Genesis Plus

LICENSE=	GPGX
LICENSE_NAME=	GPGX
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

NO_CDROM=	Commercial users must seek permission from copyright holders.

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	Genesis-Plus-GX
GH_TAGNAME=	7f83bc5

PLIST_FILES=	lib/libretro/genesis_plus_gx_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/genesis_plus_gx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
