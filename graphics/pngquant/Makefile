# Created by: Alex Hayward <xelah@xelah.com>
# $FreeBSD$

PORTNAME=	pngquant
PORTVERSION=	2.5.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=	gmake tar:bzip2
MAKE_ARGS+=	CC="${CC}"

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --ldflags)

PORTDOCS=	CHANGELOG README.md
PLIST_FILES=	bin/pngquant \
				man/man1/pngquant.1.gz

OPTIONS_DEFINE=	OPTIMIZED_FLAGS OPENMP DEBUG DOCS
OPTIONS_DEFINE_i386=	SSE

OPTIMIZED_FLAGS_CFLAGS=	-O3 -fearly-inlining -fstrict-aliasing \
		-ffast-math -funroll-loops -fomit-frame-pointer \
		-fexpensive-optimizations -ffinite-math-only \
		-funsafe-loop-optimizations -ftree-vectorize

# SSE2 support is always enabled on amd64
SSE_CFLAGS=	-DUSE_SSE=1 -msse2

OPENMP_CFLAGS=	-fopenmp
OPENMP_LDFLAGS=	-lgomp -pthread

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-$$(MAKEFLAGS)||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngquant.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
