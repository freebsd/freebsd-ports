# $FreeBSD$

PORTNAME=	libretro-dosbox
PORTVERSION=	0.20201229
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Port of DOSBox (upstream) to the libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	dosbox-libretro
GH_TAGNAME=	aa71b67

PLIST_FILES=	lib/libretro/dosbox_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/dosbox_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
