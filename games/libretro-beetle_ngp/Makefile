# $FreeBSD$

PORTNAME=	libretro-beetle_ngp
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Standalone port of Mednafen NGP to the libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	beetle-ngp-libretro
GH_TAGNAME=	6f15532

PLIST_FILES=	libexec/libretro/mednafen_ngp_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
