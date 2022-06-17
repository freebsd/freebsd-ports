PORTNAME=	openmsx
DISTVERSION=	18.0
CATEGORIES=	emulators

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Open source MSX emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora \
		libao.so:audio/libao \
		libfreetype.so:print/freetype2 \
		libasound.so:audio/alsa-lib

USES=		gl gmake pkgconfig python sdl tcl
USE_GCC=	yes
USE_GL=		gl glew
USE_SDL=	sdl2 ttf2

USE_GITHUB=	yes
GH_ACCOUNT=	openMSX
GH_PROJECT=	openMSX
GH_TAGNAME=	RELEASE_18_0

MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		OPENMSX_CXX=${CXX} \
		CXXFLAGS="${CXXFLAGS}"

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
