# New ports collection makefile for:	tclxml
# Date created:				2 May 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tclxml
PORTVERSION=	3.2
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tclxml/TclXML/${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	API for parsing XML documents using Tcl

BUILD_DEPENDS=	${LOCALBASE}/bin/xslt-config:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS?=	dtplite:${PORTSDIR}/devel/tcllib

PORTDOCS=	README.xml html.xsl man.macros nroff.xsl tcldoc-1.0.dtd \
		tcldom.html tcldom.xml tclxml.css tclxml.html tclxml.xml \
		tclxslt.html tclxslt.xml transform.tcl txt.xsl

USE_TCL=	82+
XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_LDCONFIG?=	${PREFIX}/lib/Tclxml${PORTVERSION}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		XML_CONFIG="${XML_CONFIG}"
PLIST=		${PKGDIR}${PKGNAMESUFFIX}/pkg-plist
PATCHDIR=	${PKGDIR}${PKGNAMESUFFIX}/files/
PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

pre-install:

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
