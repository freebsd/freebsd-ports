PORTNAME=	libretro-uae
PORTVERSION=	0.20200527
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro port of UAE

LICENSE=	GPLv2

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: potgo_value
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: potgo_value
BROKEN_riscv64=		fails to compile: ./sources/src/machdep/maccess.h:51:14: unrecognized instruction mnemonic

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_TAGNAME=	8333daa

LDFLAGS_i386=	-Wl,-z,notext

PLIST_FILES=	lib/libretro/puae_libretro.so

post-patch:
	${REINPLACE_CMD} 's/" GIT_VERSION/${GH_TAGNAME}"/' ${WRKSRC}/libretro/libretro.c

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/puae_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
