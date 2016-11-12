# Created by: Alex Hayward <xelah@xelah.com>
# $FreeBSD$

PORTNAME=	pngquant
PORTVERSION=	2.7.2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=	gmake pkgconfig
HAS_CONFIGURE=	yes
MAKE_ARGS+=	CC="${CC}"

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --ldflags)

PORTDOCS=	CHANGELOG README.md
PLIST_FILES=	bin/pngquant \
				man/man1/pngquant.1.gz

OPTIONS_DEFINE=	OPTIMIZED_FLAGS OPENMP LCMS2 DEBUG DOCS
OPTIONS_DEFINE_i386=	SSE
LCMS2_DESC=	Support for ICC profiles via LCMS library

DEBUG_CFLAGS_OFF=	-DNDEBUG

LCMS2_CONFIGURE_WITH=	lcms2
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2

OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp
OPENMP_CPPFLAGS=	-I${LOCALBASE}/include
OPENMP_CONFIGURE_ON=	--with-openmp
OPENMP_CONFIGURE_ENV=	C_INCLUDE_PATH=${LOCALBASE}/include

OPTIMIZED_FLAGS_CFLAGS=	-O3 -fearly-inlining -fstrict-aliasing \
		-ffast-math -funroll-loops -fomit-frame-pointer \
		-fexpensive-optimizations -ffinite-math-only \
		-funsafe-loop-optimizations -ftree-vectorize

# SSE2 support is always enabled on amd64
SSE_CFLAGS=	-DUSE_SSE=1 -msse2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngquant.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
