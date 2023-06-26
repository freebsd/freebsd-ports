PORTNAME=	libretro-pcsx_rearmed
PORTVERSION=	0.20220405
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of PCSX with ARM optimizations
WWW=		https://github.com/libretro/pcsx_rearmed

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	pcsx_rearmed
GH_TAGNAME=	46a38bd

PLIST_FILES=	lib/libretro/pcsx_rearmed_libretro.so

MAKEFILE=	Makefile.libretro

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/pcsx_rearmed_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.post.mk>
