# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	openclonk
DISTVERSION=	8.1
PORTREVISION=	2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${DISTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer action game involving small and nimble humanoids

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

WRKSRC=		${WRKDIR}/openclonk-release-${PORTVERSION}-src

# make install has parallel issues with ninja
USES=		compiler:c++14-lang cmake:noninja desktop-file-utils gl jpeg \
		openal pkgconfig sdl tar:bzip2 xorg
USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_XORG=	x11 xpm
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DAudio_TK:STRING="OpenAL"
LLD_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION games|DESTINATION bin|' \
		-e 's|share/games|share|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
