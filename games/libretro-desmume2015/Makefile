PORTNAME=	libretro-desmume2015
DISTVERSION=	0.20220405
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of Desmume to libretro based on Desmume SVN circa 2015
WWW=		https://github.com/libretro/desmume2015

LICENSE=	GPLv2

BROKEN_aarch64=	fails to compile: invokes x86 assembler

USES=		compiler:c++11-lib gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	desmume2015
GH_TAGNAME=	af397ff3d1f208c27f3922cc8f2b8e08884ba893

PLIST_FILES=	lib/libretro/desmume2015_libretro.so

MAKEFILE=	Makefile.libretro
BUILD_WRKSRC=	${WRKSRC}/desmume

.include <bsd.port.options.mk>

.if ${ARCH} != aarch64 && ${ARCH} != amd64 && !${ARCH:Marmv*} && ${ARCH} != i386
MAKE_ENV+=	DESMUME_JIT=0
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/desmume/desmume2015_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
