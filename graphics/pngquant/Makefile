PORTNAME=	pngquant
PORTVERSION=	2.18.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://pngquant.org/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs
WWW=		https://pngquant.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libimagequant.so:graphics/libimagequant \
		libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cpe gmake pkgconfig
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libimagequant

PORTDOCS=	CHANGELOG README.md
PLIST_FILES=	bin/pngquant \
				share/man/man1/pngquant.1.gz

OPTIONS_DEFINE=	OPTIMIZED_FLAGS OPENMP LCMS2 DEBUG DOCS
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFINE_amd64=	SSE
LCMS2_DESC=	Support for ICC profiles via LCMS library
OPTIMIZED_FLAGS_DESC=	${OPTIMIZED_CFLAGS_DESC}
OPTIONS_DEFAULT=	OPENMP
OPTIONS_DEFAULT_amd64=	SSE

DEBUG_CONFIGURE_ON=	--enable-debug

LCMS2_CONFIGURE_WITH=	lcms2
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2

OPENMP_CONFIGURE_WITH=	openmp
.if !exists(/usr/include/omp.h)
OPENMP_USES=		compiler:gcc-c++11-lib
.endif

OPTIMIZED_FLAGS_CFLAGS=	-O3 -fstrict-aliasing \
		-ffast-math -funroll-loops -fomit-frame-pointer \
		-fexpensive-optimizations -ffinite-math-only \
		-funsafe-loop-optimizations -ftree-vectorize

SSE_CONFIGURE_ENABLE=sse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngquant.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
