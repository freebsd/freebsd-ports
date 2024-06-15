PORTNAME=	libretro-pcsx_rearmed
DISTVERSION=	0.20231025
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
GH_TAGNAME=	2636d7c22592b7e926af67144ab2feee18ecd53d

PLIST_FILES=	lib/libretro/pcsx_rearmed_libretro.so

MAKEFILE=	Makefile.libretro

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
MAKE_ARGS+=	DYNAREC=ari64 ARCH=arm
.endif
.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/pcsx_rearmed_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.post.mk>
