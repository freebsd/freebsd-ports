PORTNAME=	pdf2djvu
DISTVERSION=	0.9.19
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	https://github.com/jwilk/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	samy.mahmoudi@gmail.com
COMMENT=	Creates DjVu files from PDF files
WWW=		https://jwilk.net/software/pdf2djvu

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/pstreams/pstream.h:devel/pstreams
LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libpoppler.so:graphics/poppler

USES=		autoreconf:build compiler:c++17-lang gettext-tools \
		gmake iconv localbase pkgconfig tar:xz
USE_CXXSTD=	c++17

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	COLOR_QUANTIZATION DOCS NLS MULTITHREADING XMP
OPTIONS_DEFAULT=COLOR_QUANTIZATION          MULTITHREADING
OPTIONS_SUB=	yes

COLOR_QUANTIZATION_DESC=Color quantization via GraphicsMagick++
DOCS_DESC=		Generate the man page
MULTITHREADING_DESC=	Multithreading support via OpenMP
NLS_DESC=		Native Language Support via gettext utilities
XMP_DESC=		XMP metadata support via Exiv2

COLOR_QUANTIZATION_LIB_DEPENDS=	\
		libGraphicsMagick++.so:graphics/GraphicsMagick \
		libGraphicsMagick.so:graphics/GraphicsMagick
COLOR_QUANTIZATION_CONFIGURE_WITH=graphicsmagick

DOCS_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

MULTITHREADING_CONFIGURE_ENABLE=openmp

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

XMP_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
XMP_CONFIGURE_ENABLE=	xmp

post-build-DOCS-on:
	@cd ${WRKSRC}/doc && ${GMAKE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
