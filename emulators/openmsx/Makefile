# $FreeBSD$

PORTNAME=	openmsx
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Open source MSX emulator

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libao.so:${PORTSDIR}/audio/libao

MAKE_ARGS+=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		OPENMSX_CXX=${CXX} \
		CXXFLAGS="${CXXFLAGS}"

MAKEFILE=	GNUmakefile
USES=		gmake tcl
USE_GCC=	yes
USE_GL=		glew
USE_SDL=	sdl ttf
USE_PYTHON=	yes

PLIST_FILES=	bin/openmsx
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.ifdef	NOPORTDATA
IGNORE=		opemsx requires port data, unset NOPORTDATA to install
.endif

.if !${PORT_OPTIONS:MDOCS}
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR=${WRKSRC}/dummy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/{TCL_LIB_SPEC}/& $${TCL_LD_FLAGS}/' \
		${WRKSRC}/build/libraries.py
	@${REINPLACE_CMD} -e '/^SYMLINK_FOR_BINARY/s/true/false/' \
		${WRKSRC}/build/custom.mk

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: uses i386-specific asm
.endif

.include <bsd.port.post.mk>
