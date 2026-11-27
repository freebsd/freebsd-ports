PORTNAME=	tesseract
PORTVERSION=	5.5.5
CATEGORIES=	graphics

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine
WWW=		https://github.com/tesseract-ocr/tesseract

LICENSE=	APACHE20

LIB_DEPENDS=	liblept.so:graphics/leptonica
RUN_DEPENDS=	tesseract-data>=0:graphics/tesseract-data

USES=		autoreconf compiler:c++20-lang cpe libtool localbase pathfix \
		pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPE_VENDOR=	tesseract_project

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-ocr

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README.md
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CURL DOCS LIBARCHIVE MANPAGES TOOLS
OPTIONS_DEFAULT=	CURL LIBARCHIVE MANPAGES TOOLS
OPTIONS_SUB=	yes

.if exists(/usr/include/omp.h)
OPTIONS_DEFINE+=	OPENMP
OPTIONS_DEFAULT+=	OPENMP
.endif

CURL_DESC=	Read input images from URLs via cURL
LIBARCHIVE_DESC=	Compressed traineddata support via libarchive
TOOLS_DESC=	Include training tools

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

LIBARCHIVE_USES=	libarchive
LIBARCHIVE_CONFIGURE_WITH=	archive

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_CONFIGURE_ENABLE=	doc

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=	-lomp

TOOLS_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libicui18n.so:devel/icu
TOOLS_USES=	gnome
TOOLS_USE=	GNOME=cairo,glib20,pango

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-TOOLS-on:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${STAGEDIR} training-install

.include <bsd.port.mk>
