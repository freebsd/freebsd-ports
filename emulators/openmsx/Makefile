PORTNAME=	openmsx
DISTVERSION=	20.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/openMSX/openMSX/releases/download/RELEASE_20_0/

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Open source MSX emulator
WWW=		https://openmsx.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	libao.so:audio/libao \
		libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++20-lang gl gmake pkgconfig python sdl tcl

USE_GL=		gl glew
USE_SDL=	sdl2 ttf2

CXXFLAGS+=	-I/usr/include/c++/v1 -std=c++20

MAKEFILE=	GNUmakefile
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}" \
		INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_DOC_DIR=${DOCSDIR} \
		INSTALL_SHARE_DIR=${DATADIR} \
		OPENMSX_CXX=${CXX}

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
