# $FreeBSD$

PORTNAME=	openmsx
PORTVERSION=	0.13.0
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/openMSX/openMSX/releases/download/RELEASE_${PORTVERSION:S/./_/g}/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Open source MSX emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora \
		libao.so:audio/libao

MAKEFILE=	GNUmakefile
USES=		gmake python:2.7 tcl
USE_GCC=	yes
USE_GL=		glew
USE_SDL=	sdl ttf

MAKE_ARGS=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		OPENMSX_CXX=${CXX} \
		CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/openmsx
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# Use dummy target rather than rewriting makefile
DOCS_MAKE_ARGS_OFF=	INSTALL_DOC_DIR=${WRKSRC}/dummy

post-patch:
	@${REINPLACE_CMD} -e 's/{TCL_LIB_SPEC}/& $${TCL_LD_FLAGS}/' \
		${WRKSRC}/build/libraries.py
	@${REINPLACE_CMD} -e '/^SYMLINK_FOR_BINARY/s/true/false/' \
		${WRKSRC}/build/custom.mk

.include <bsd.port.mk>
