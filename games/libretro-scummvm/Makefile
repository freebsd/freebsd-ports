# $FreeBSD$

PORTNAME=	libretro-scummvm
PORTVERSION=	0.20201129
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	ScummVM with libretro backend

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	scummvm
GH_TAGNAME=	7b1e929

PLIST_FILES=	lib/libretro/scummvm_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/backends/platform/libretro/build/scummvm_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
