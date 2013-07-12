# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	liblqr-1
DISTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wdfiles.com/local--files/en:download-page/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An easy to use C/C++ seam carving library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	_glib20
USES=		gettext pkgconfig
MAKE_JOBS_SAFE=	yes
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
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.if !exists(${LOCALBASE}/lib/libpngwriter.a)
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.endif
.endif

.include <bsd.port.mk>
