PORTNAME=	libretro-desmume
DISTVERSION=	0.20231006
CATEGORIES=	games

MAINTAINER=	sdalu@sdalu.com
COMMENT=	Port of Desmume to libretro
WWW=		https://github.com/libretro/desmume

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS= amd64 i386
ONLY_FOR_ARCHS_REASON= fails to compile: invokes x86 assembler

USES=		gmake gl localbase:ldflags
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	desmume
GH_TAGNAME=	4ee1bb1d6a6c9695baea49d0c2dff34c10187502

PLIST_FILES=	lib/libretro/desmume_libretro.so

MAKEFILE=	Makefile.libretro
BUILD_WRKSRC=	${WRKSRC}/desmume/src/frontend/libretro

.include <bsd.port.options.mk>

.if ${ARCH} != aarch64 && ${ARCH} != amd64 && !${ARCH:Marmv*} && ${ARCH} != i386
MAKE_ENV+=	DESMUME_JIT=0
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/desmume/src/frontend/libretro/desmume_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.mk>
