# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	tclxml
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	LOCAL/bf SF/tclxml/TclXML/${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	API for parsing XML documents using Tcl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxslt.so:textproc/libxslt
RUN_DEPENDS?=	dtplite:devel/tcllib

PORTDOCS=	README.xml html.xsl man.macros nroff.xsl tcldoc-1.0.dtd \
		tcldom.html tcldom.xml tclxml.css tclxml.html tclxml.xml \
		tclxslt.html tclxslt.xml transform.tcl txt.xsl

USES=		tcl:tea tar:xz
TCL_PKG=	Tclxml${PORTVERSION}
PLIST_SUB=	PORTVERSION=${PORTVERSION}
XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
CONFIGURE_ARGS+=XML_CONFIG="${XML_CONFIG}"

OPTIONS_DEFINE=	DOCS
MAKE_ENV+=	TCLLIBPATH=${STAGEDIR}/${PREFIX}/lib

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e '/^TCLSH_ENV[[:blank:]]*=/,/[^\]$$/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/FreeBSD-*|DragonFly-*/g' \
		${WRKSRC}/configure

post-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} doc)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
