PORTNAME=	libretro-puae
DISTVERSION=	0.20231014
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretro port of UAE
WWW=		https://github.com/libretro/libretro-uae

LICENSE=	GPLv2

BROKEN_riscv64=		fails to compile: ./sources/src/machdep/maccess.h:51:14: unrecognized instruction mnemonic

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	libretro-uae
GH_TAGNAME=	e13578877d1764bde7d6fb5b404c0965fa209540

CFLAGS+=	-fcommon

LDFLAGS_i386=	-Wl,-z,notext

PLIST_FILES=	lib/libretro/puae_libretro.so

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/puae_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
