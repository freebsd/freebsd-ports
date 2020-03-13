# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tesseract
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LICENSE=	APACHE20

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	liblept.so:graphics/leptonica
RUN_DEPENDS=	tesseract-data>=0:graphics/tesseract-data

USES=		autoreconf compiler:c++11-lang gmake gnome localbase \
		libtool pathfix pkgconfig shebangfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-ocr

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica"

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README.md
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	src/training/language-specific.sh \
		src/training/tesstrain.sh

OPTIONS_DEFINE=	DOCS TOOLS
OPTIONS_DEFINE_amd64=OPENMP
OPTIONS_DEFINE_i386=OPENMP
OPTIONS_DEFAULT=TOOLS
OPTIONS_DEFAULT_amd64=OPENMP
OPTIONS_DEFAULT_i386=OPENMP
OPTIONS_SUB=	yes

OPENMP_CONFIGURE_ENABLE=openmp

TOOLS_DESC=	Include training tools
TOOLS_LIB_DEPENDS=libicui18n.so:devel/icu \
		libfontconfig.so:x11-fonts/fontconfig
TOOLS_USE=	GNOME=cairo,glib20,pango

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -DNDEBUG||' ${WRKSRC}/configure.ac

post-build-TOOLS-on:
	@cd ${WRKSRC} && ${MAKE} training

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-TOOLS-on:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${STAGEDIR} training-install

.include <bsd.port.mk>
