# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	liblqr-1
DISTVERSION=	0.4.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wdfiles.com/local--files/en:download-page/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Easy to use C/C++ seam carving library

USES=		tar:bzip2 gettext gmake pkgconfig libtool:oldver
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# Use GNU89 inline semantics
USE_CSTD=	gnu89

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES HTMLDOCS
HTMLDOCS_DESC=	Build and install HTML documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}
.endif

.if ${PORT_OPTIONS:MHTMLDOCS}
BUILD_DEPENDS+=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml
PLIST_SUB=	HTMLDOCS=""
.else
PLIST_SUB=	HTMLDOCS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^lqr_pkgconfigdir/ s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr.*chunk\.xsl|${LOCALBASE}/share/xsl/docbook/html/chunk.xsl|' \
		${WRKSRC}/docs/lqr_style.xsl
	@${REINPLACE_CMD} -e 's|/usr.*docbookx.dtd|${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd|' \
		${WRKSRC}/docs/liblqr_manual.docbook

.if ${PORT_OPTIONS:MHTMLDOCS}
post-build:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} html
.endif

post-install:
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
