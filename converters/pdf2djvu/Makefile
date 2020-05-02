# $FreeBSD$

PORTNAME=	pdf2djvu
DISTVERSION=	0.9.17
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	https://github.com/jwilk/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	samy.mahmoudi@gmail.com
COMMENT=	Creates DjVu files from PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:devel/pstreams
LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libpoppler.so:graphics/poppler

USES=		autoreconf:build compiler:c++11-lang gettext-tools \
		gmake iconv localbase pkgconfig tar:xz
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	COLOR_QUANTIZATION DOCS NLS MULTITHREADING XMP
OPTIONS_DEFAULT=COLOR_QUANTIZATION          MULTITHREADING XMP
OPTIONS_SUB=	yes

COLOR_QUANTIZATION_DESC=Color quantization via GraphicsMagick++
DOCS_DESC=		Generate the man page
NLS_DESC=		Native Language Support via gettext utilities
MULTITHREADING_DESC=	Multithreading support via OpenMP
XMP_DESC=		XMP metadata support via Exiv2

COLOR_QUANTIZATION_CONFIGURE_WITH=graphicsmagick
COLOR_QUANTIZATION_LIB_DEPENDS=	\
		libGraphicsMagick++.so:graphics/GraphicsMagick \
		libGraphicsMagick.so:graphics/GraphicsMagick

DOCS_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

MULTITHREADING_CONFIGURE_ENABLE=openmp

XMP_CONFIGURE_ENABLE=	xmp
XMP_LIB_DEPENDS=	libexiv2.so:graphics/exiv2

pre-configure:
	@cd ${WRKSRC} && ${SH} ${FILESDIR}/bootstrap

post-build-DOCS-on:
	@cd ${WRKSRC}/doc && ${GMAKE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
