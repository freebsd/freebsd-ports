PORTNAME=	libretro-bsnes
DISTVERSIONPREFIX=	v
DISTVERSION=	115.a.20231101
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Standalone port of bSNES to libretro
WWW=		https://github.com/libretro/bsnes-libretro

LICENSE=	GPLv3

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	bsnes-libretro
GH_TAGNAME=	0685381

USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/bsnes_libretro.so

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/bsnes_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
