PORTNAME=	liblqr-1
PORTVERSION=	0.4.2
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wdfiles.com/local--files/en:download-page/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Easy to use C/C++ seam carving library
WWW=		https://liblqr.wikidot.com/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		gettext gmake gnome libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# Use GNU89 inline semantics
USE_CSTD=	gnu89

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES HTMLDOCS
OPTIONS_SUB=	yes
HTMLDOCS_DESC=	Build and install HTML documentation

EXAMPLES_SUB_FILES=	pkg-message
EXAMPLES_SUB_LIST=	PORTSDIR=${PORTSDIR}

HTMLDOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
			docbook-xml>0:textproc/docbook-xml

post-patch:
	@${REINPLACE_CMD} -e '/^lqr_pkgconfigdir/ s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr.*chunk\.xsl|${LOCALBASE}/share/xsl/docbook/html/chunk.xsl|' \
		${WRKSRC}/docs/lqr_style.xsl
	@${REINPLACE_CMD} -e 's|/usr.*docbookx.dtd|${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd|' \
		${WRKSRC}/docs/liblqr_manual.docbook

post-build-HTMLDOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} html

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

post-install-HTMLDOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
