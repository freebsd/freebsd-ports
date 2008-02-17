# New ports collection makefile for:	liblqr-1
# Date created:		30 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	liblqr-1
DISTVERSION=	0.1.0-1
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wikidot.com/local--files/en:download-page/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	An easy to use C/C++ seam carving library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/^([0-9.]+)-([0-9]+)$/\1/}

USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl

PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*

PKGMESSAGE=	${WRKDIR}/pkg_message
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^lqr_pkgconfigdir/ s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr.*chunk\.xsl|${LOCALBASE}/share/xsl/docbook/html/chunk.xsl|' \
		${WRKSRC}/docs/lqr_style.xsl

post-build:
.if !defined(NOPORTDOCS)
	${RM} ${WRKSRC}/examples/*.orig
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} xml
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
