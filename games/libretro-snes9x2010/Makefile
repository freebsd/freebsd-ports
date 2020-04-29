# $FreeBSD$

PORTNAME=	libretro-snes9x2010
PORTVERSION=	0.20200317
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Snes9x - Portable Super Nintendo emulator (1.52)

LICENSE=	PS
LICENSE_NAME=	PS
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

NO_CDROM=	Commercial users must seek permission from copyright holders.

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	snes9x2010
GH_TAGNAME=	ba9f224

PLIST_FILES=	libexec/libretro/snes9x2010_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
