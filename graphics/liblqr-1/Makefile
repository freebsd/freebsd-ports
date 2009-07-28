# New ports collection makefile for:	liblqr-1
# Date created:		30 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	liblqr-1
DISTVERSION=	0.4.1
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wdfiles.com/local--files/en:download-page/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An easy to use C/C++ seam carving library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 pkgconfig
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450

PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*

PKGMESSAGE=	${WRKDIR}/pkg_message
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e 's|FVISIBILITY_FLAG=".*"|FVISIBILITY_FLAG=""|' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e '/^lqr_pkgconfigdir/ s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr.*chunk\.xsl|${LOCALBASE}/share/xsl/docbook/html/chunk.xsl|' \
		${WRKSRC}/docs/lqr_style.xsl
	@${REINPLACE_CMD} -e 's|/usr.*docbookx.dtd|${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd|' \
		${WRKSRC}/docs/liblqr_manual.docbook

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

	@${ECHO_CMD} "==========================================================================" >> ${PKGMESSAGE}
	@${ECHO_CMD} "NOTE: In order to compile examples for liblrq, you will" >> ${PKGMESSAGE}
	@${ECHO_CMD} "also need pngwriter port (${PORTSDIR}/graphics/pngwriter)." >> ${PKGMESSAGE}
	@${ECHO_CMD} "Examples are located in ${EXAMPLESDIR}" >> ${PKGMESSAGE}
	@${ECHO_CMD} "==========================================================================" >> ${PKGMESSAGE}

.if !exists(${LOCALBASE}/lib/libpngwriter.a)
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}
.endif
.endif

.include <bsd.port.post.mk>
