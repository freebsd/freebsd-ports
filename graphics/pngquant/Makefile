# New ports collection makefile for:	pngcquant
# Date created:				Fri 08 Feb 2002
# Whom:					Alex Hayward <xelah@xelah.com>
#
# $FreeBSD$
#

PORTNAME=	pngquant
PORTVERSION=	1.7.2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

OPTIONS=	OPTIMIZED_CFLAGS "Additional optimization" off \
		OPENMP "Enable OpenMP support" off \
		SSE2 "Enable x86 SSE2 optimization" off

NO_WRKSUBDIR=	yes

USE_BZIP2=	yes
USE_CSTD=	c99
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CFLAGS+=	`libpng-config --I_opts`
LDFLAGS+=	`libpng-config --ldflags`

MAN1=		pngquant.1
PORTDOCS=	CHANGELOG README.md
PLIST_FILES=	bin/pngquant

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fearly-inlining -fstrict-aliasing -ffast-math \
		-funroll-loops -fomit-frame-pointer -fexpensive-optimizations \
		-ffinite-math-only -funsafe-loop-optimizations -ftree-vectorize
.endif

.if defined(WITH_OPENMP)
CFLAGS+=	${PTHREAD_CFLAGS} -fopenmp
LDFLAGS+=	${PTHREAD_LIBS} -lgomp
.endif

# SSE2 support is always enabled on amd64
.if defined(WITH_SSE2) && ${ARCH} == "i386"
CFLAGS+=	-DUSE_SSE=1 -msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngquant.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
