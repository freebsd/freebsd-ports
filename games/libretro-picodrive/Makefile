# $FreeBSD$

PORTNAME=	libretro-picodrive
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Fast MegaDrive/MegaCD/32X emulator

LICENSE=	PD

BROKEN_aarch64=	error: unsupported arch

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	picodrive
GH_TAGNAME=	600894e

PLIST_FILES=	libexec/libretro/picodrive_libretro.so

MAKEFILE=	Makefile.libretro

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
