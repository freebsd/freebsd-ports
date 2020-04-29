# $FreeBSD$

PORTNAME=	libretro-dosbox
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Port of DOSBox (upstream) to the libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	dosbox-libretro
GH_TAGNAME=	e4ed503

PLIST_FILES=	libexec/libretro/dosbox_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
