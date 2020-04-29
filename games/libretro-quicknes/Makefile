# $FreeBSD$

PORTNAME=	libretro-quicknes
PORTVERSION=	0.20200317
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	NES emulator core for libretro

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	QuickNES_Core
GH_TAGNAME=	3165481

PLIST_FILES=	libexec/libretro/quicknes_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
