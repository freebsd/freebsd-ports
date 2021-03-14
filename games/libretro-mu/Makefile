# $FreeBSD$

PORTNAME=	libretro-mu
PORTVERSION=	0.20210214
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	PalmOS emulator to the libretro API

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	Mu
GH_TAGNAME=	ff746b8

PLIST_FILES=	lib/libretro/mu_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/libretroBuildSystem/mu_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
