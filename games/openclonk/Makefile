PORTNAME=	openclonk
DISTVERSION=	8.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${DISTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer action game involving small and nimble humanoids
WWW=		https://www.openclonk.org/

LICENSE=	ISCL CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: C4Texture.cpp:260:13: error: 'stoul' is not a member of 'std'

LIB_DEPENDS=	libalut.so:audio/freealut \
		libfreetype.so:print/freetype2 \
		libminiupnpc.so:net/miniupnpc \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libtinyxml.so:textproc/tinyxml \
		libvorbis.so:audio/libvorbis

# make install has parallel issues with ninja
USES=		cmake:noninja compiler:c++14-lang desktop-file-utils gl gnome jpeg openal \
		pkgconfig sdl tar:bzip2 xorg
USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_XORG=	x11 xpm
CMAKE_ARGS=	-DAudio_TK:STRING="OpenAL"
CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
LDFLAGS_i386=	-Wl,-znotext
WRKSRC=		${WRKDIR}/openclonk-release-${PORTVERSION}-src

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang"
LDFLAGS_i386+=  -Wl,--no-check-dynamic-relocations
.endif

.include <bsd.port.post.mk>
