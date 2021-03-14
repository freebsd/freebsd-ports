# $FreeBSD$

PORTNAME=	libretro-prosystem
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Port of ProSystem to the libretro API

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	prosystem-libretro
GH_TAGNAME=	a812cab

PLIST_FILES=	lib/libretro/prosystem_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
