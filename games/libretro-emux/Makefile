# $FreeBSD$

PORTNAME=	libretro-emux
PORTVERSION=	0.20200313
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Emux is a cross-platform emulator project supporting various machines

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	emux
GH_TAGNAME=	640d4ba

PLIST_FILES=	libexec/libretro/emux_chip8_libretro.so \
		libexec/libretro/emux_gb_libretro.so \
		libexec/libretro/emux_nes_libretro.so \
		libexec/libretro/emux_sms_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
