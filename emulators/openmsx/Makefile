# New ports collection makefile for:	openmsx
# Date created:				20 January 2006
# Whom:					Johan van Selst <johans@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	openmsx
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	johans@stack.nl
COMMENT=	Open source MSX emulator

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		jack:${PORTSDIR}/audio/jack \
		GLEW:${PORTSDIR}/graphics/glew \
		png:${PORTSDIR}/graphics/png

MAKE_ARGS+=	INSTALL_BINARY_DIR=${PREFIX}/bin \
		INSTALL_SHARE_DIR=${DATADIR} \
		INSTALL_DOC_DIR=${DOCSDIR} \
		TCL_CONFIG_DIR=${TCL_LIBDIR} \
		OPENMSX_CXX=${CXX}

MAKEFILE=	GNUmakefile
USE_GMAKE=	yes
USE_TCL=	84
USE_TCL_BUILD=	84
USE_SDL=	sdl image

.ifdef(NOPORTDOCS)
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR=${WRKSRC}/dummy
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000 && ${ARCH} == "amd64"
BROKEN=		internal compiler error on 5.x/amd64
.endif

post-patch:
.if ${OSVERSION} < 503000
	@${REINPLACE_CMD} -e 's/round/rint/' ${WRKSRC}/src/Math.hh
.endif

.include <bsd.port.post.mk>
