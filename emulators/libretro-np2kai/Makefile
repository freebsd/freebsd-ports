PORTNAME=	libretro-np2kai
DISTVERSIONPREFIX=	rev.
DISTVERSION=	22.20260905
CATEGORIES=	emulators games

MAINTAINER=	benoit.felix@outlook.com
COMMENT=	Neko Project II kai (NEC PC-9801) core for libretro
WWW=		https://github.com/AZO234/NP2kai

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix gmake
DOS2UNIX_FILES=	sdl/Makefile.common
USE_GITHUB=	yes
GH_ACCOUNT=	AZO234
GH_PROJECT=	NP2kai
GH_TAGNAME=	5939e0c6d5985c4c08fc70f289a83290e5d3e6f7

MAKEFILE=	Makefile.libretro
# Upstream takes the version from git unless these are set
MAKE_ARGS=	NP2KAI_VERSION=rev.22 \
		NP2KAI_HASH=5939e0c

BUILD_WRKSRC=	${WRKSRC}/sdl

PLIST_FILES=	lib/libretro/np2kai_libretro.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${BUILD_WRKSRC}/np2kai_libretro.so \
		${STAGEDIR}${PREFIX}/lib/libretro

.include <bsd.port.mk>
