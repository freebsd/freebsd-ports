# Created by: Alex Hayward <xelah@xelah.com>
# $FreeBSD$

PORTNAME=	pngquant
PORTVERSION=	1.8.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS OPENMP DEBUG DOCS
OPTIONS_DEFINE_i386=	SSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_CSTD=	c99
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --ldflags) -lz -lm

MAN1=		pngquant.1
PORTDOCS=	CHANGELOG README.md
PLIST_FILES=	bin/pngquant

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fearly-inlining -fstrict-aliasing -ffast-math \
		-funroll-loops -fomit-frame-pointer -fexpensive-optimizations \
		-ffinite-math-only -funsafe-loop-optimizations -ftree-vectorize
.endif

.if ${PORT_OPTIONS:MOPENMP}
CFLAGS+=	${PTHREAD_CFLAGS} -fopenmp
LDFLAGS+=	${PTHREAD_LIBS} -lgomp
.endif

# SSE2 support is always enabled on amd64
.if ${PORT_OPTIONS:MSSE}
CFLAGS+=	-DUSE_SSE=1 -msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngquant.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
.endif

.include <bsd.port.mk>
