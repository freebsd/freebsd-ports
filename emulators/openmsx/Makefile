# $FreeBSD$

PORTNAME=	openmsx
PORTVERSION=	0.9.1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Open source MSX emulator

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		png15:${PORTSDIR}/graphics/png \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		theora:${PORTSDIR}/multimedia/libtheora

MAKE_ARGS+=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		OPENMSX_CXX=${CXX}

MAKEFILE=	GNUmakefile
USE_GL=		glew
USE_GMAKE=	yes
USE_TCL=	85+
USE_SDL=	sdl ttf
USE_PYTHON=	2.5+

PLIST_FILES=	bin/openmsx
PORTDATA=	*
PORTDOCS=	*

.ifdef	NOPORTDATA
IGNORE=		opemsx requires port data, unset NOPORTDATA to install
.endif

.ifdef	NOPORTDOCS
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR=${WRKSRC}/dummy
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/{TCL_LIB_SPEC}/& $${TCL_LD_FLAGS}/' \
		${WRKSRC}/build/libraries.py
	@${REINPLACE_CMD} -e '/^SYMLINK_FOR_BINARY/s/true/false/' \
		${WRKSRC}/build/custom.mk

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
USE_GCC=	4.2+
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: uses i386-specific asm
.endif

.include <bsd.port.post.mk>
