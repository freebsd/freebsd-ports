# $FreeBSD$

PORTNAME=	libretro-fbalpha
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Final Burn Alpha port for libretro

LICENSE=	FBA
LICENSE_NAME=	FBA
LICENSE_FILE=	${WRKSRC}/src/license.txt
LICENSE_PERMS=  dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

PLIST_FILES=	libexec/libretro/fbalpha_libretro.so

NO_CDROM=       Commercial users must seek permission from copyright holders.

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	fbalpha
GH_TAGNAME=	84eb9d9

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
