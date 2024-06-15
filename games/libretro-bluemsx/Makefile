PORTNAME=	libretro-bluemsx
DISTVERSION=	0.20230417
CATEGORIES=	games

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Port of blueMSX to the libretro API
WWW=		https://github.com/libretro/blueMSX-libretro

LICENSE=	GPLv3

USES=		compiler:c++11-lib gmake
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	blueMSX-libretro
GH_TAGNAME=	e21bf74bddb79ad1bbe20b4d964e7515269c669b
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libretro/bluemsx_libretro.so

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/bluemsx_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro

.include <bsd.port.post.mk>
