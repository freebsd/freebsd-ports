# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	tesseract
PORTVERSION=	5.0.0
CATEGORIES=	graphics

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LICENSE=	APACHE20

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	liblept.so:graphics/leptonica \
		libtiff.so:graphics/tiff \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2 \
		libcurl.so:ftp/curl

RUN_DEPENDS=	tesseract-data>=0:graphics/tesseract-data

USES=		compiler:c++11-lang cmake cpe gnome libarchive libtool \
		localbase pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPE_VENDOR=	tesseract_project

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-ocr

CMAKE_ON=	BUILD_SHARED_LIBS
DATADIR=	${PREFIX}/share/tessdata
LDFLAGS+=	-pthread
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	DOCS OPENMP TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_DEFAULT_i386=	OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_SUB=	yes

OPENMP_CMAKE_BOOL=	OPENMP_BUILD

TOOLS_CMAKE_BOOL=	BUILD_TRAINING_TOOLS
TOOLS_DESC=	Include training tools
TOOLS_LIB_DEPENDS=libicui18n.so:devel/icu \
		libfontconfig.so:x11-fonts/fontconfig
TOOLS_USE=	GNOME=cairo,glib20,pango

.include <bsd.port.options.mk>

.if ${ARCH} != powerpc64 && ${ARCH} != riscv64
CMAKE_ARGS+=	-DENABLE_LTO:BOOL=ON
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-TOOLS-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/training/libcommon_training.so \
		${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/training/libpango_training.so \
		${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/training/libunicharset_training.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
