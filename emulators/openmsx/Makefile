# New ports collection makefile for:	openmsx
# Date created:				20 January 2006
# Whom:					Johan van Selst <johans@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	openmsx
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Open source MSX emulator

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		png:${PORTSDIR}/graphics/png \
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

.ifdef(NOPORTDOCS)
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR=${WRKSRC}/dummy
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SYMLINK_FOR_BINARY/s/true/false/' \
		${WRKSRC}/build/custom.mk

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
