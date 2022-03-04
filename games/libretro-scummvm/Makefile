PORTNAME=	libretro-scummvm
PORTVERSION=	0.20201129
CATEGORIES=	games

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	ScummVM with libretro backend

LICENSE=	GPLv2

BROKEN_FreeBSD_13=	engines/sludge/loadsave.cpp:201:10: error: cannot initialize return object of type 'bool' with an rvalue of type 'nullptr_t'
BROKEN_FreeBSD_14=	engines/sludge/loadsave.cpp:201:10: error: cannot initialize return object of type 'bool' with an rvalue of type 'nullptr_t'

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
