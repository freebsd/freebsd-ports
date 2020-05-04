# $FreeBSD$

PORTNAME=	openmsx
PORTVERSION=	0.15.0
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	menelkir@itroll.org
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

USES=		gl gmake python sdl tcl
USE_GCC=	yes
USE_GL=		gl glew
USE_SDL=	sdl2 ttf2

USE_GITHUB=	yes
GH_ACCOUNT=	openMSX
GH_PROJECT=	openMSX
GH_TAGNAME=	0f2b558

BINARY_ALIAS=	python3=${PYTHON_CMD}

MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		OPENMSX_CXX=${CXX} \
		CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/openmsx
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/{TCL_LIB_SPEC}/& $${TCL_LD_FLAGS}/' \
		${WRKSRC}/build/libraries.py
	@${REINPLACE_CMD} -e '/^SYMLINK_FOR_BINARY/s/true/false/' \
		${WRKSRC}/build/custom.mk

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
