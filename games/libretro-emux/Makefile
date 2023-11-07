PORTNAME=	libretro-emux
DISTVERSION=	0.20191014
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform emulator project supporting various machines
WWW=		https://github.com/libretro/emux

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	emux
GH_TAGNAME=	640d4bae7d4757f5377dbeb42f2d02763895095c

PLIST_FILES=	lib/libretro/emux_chip8_libretro.so \
		lib/libretro/emux_gb_libretro.so \
		lib/libretro/emux_nes_libretro.so \
		lib/libretro/emux_sms_libretro.so

BUILD_WRKSRC=	${WRKSRC}/libretro
MAKEFILE=	Makefile.bsd

EMUX_MACHINES=	chip8 gb nes sms

do-build:
.    for machine in ${EMUX_MACHINES}
	(cd ${BUILD_WRKSRC}; ${DO_MAKE_BUILD} MACHINE=${machine})
.    endfor

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
.    for machine in ${EMUX_MACHINES}
	${INSTALL_LIB} ${WRKSRC}/libretro/emux_${machine}_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro
.     endfor

.include <bsd.port.mk>
