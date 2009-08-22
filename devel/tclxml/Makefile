# New ports collection makefile for:	tclxml
# Date created:				2 May 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tclxml
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tclxml/TclXML/${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	API for parsing XML documents using Tcl

RUN_DEPENDS?=	dtplite:${PORTSDIR}/devel/tcllib

PORTDOCS=	README.html html.xsl nroff.xsl tclxml.html tclxml.xml \
		README.xml man.macros tcldoc-1.0.dtd tclxml.n txt.xsl

USE_TCL=	82+
GNU_CONFIGURE=	yes
USE_LDCONFIG?=	${PREFIX}/lib/Tclxml${PORTVERSION}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
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
