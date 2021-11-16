# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	tesseract
PORTVERSION=	4.1.3
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
		libfreetype.so:print/freetype2

RUN_DEPENDS=	tesseract-data>=0:graphics/tesseract-data

USES=		compiler:c++11-lang cmake cpe gnome libarchive libtool \
		localbase pathfix pkgconfig shebangfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPE_VENDOR=	tesseract_project

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-ocr

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica"

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README.md
SHEBANG_FILES=	src/training/language-specific.sh \
		src/training/tesstrain.sh

OPTIONS_DEFINE=	DOCS TOOLS
#OPTIONS_DEFINE_amd64=	OPENMP
#OPTIONS_DEFINE_i386=	OPENMP
#OPTIONS_DEFINE_powerpc64=	OPENMP
#OPTIONS_DEFINE_powerpc64le=	OPENMP
OPTIONS_DEFAULT=	TOOLS
#OPTIONS_DEFAULT_amd64=	OPENMP
#OPTIONS_DEFAULT_i386=	OPENMP
#OPTIONS_DEFAULT_powerpc64=	OPENMP
#OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_SUB=	yes

#OPENMP_CMAKE_BOOL=	OPENMP_BUILD

TOOLS_CMAKE_ON=	BUILD_TRAINING_TOOLS
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

.include <bsd.port.mk>
