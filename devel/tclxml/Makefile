# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	tclxml
PORTVERSION=	3.3
CATEGORIES=	devel tcl
MASTER_SITES=	LOCAL/bf SF/tclxml/TclXML/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for parsing XML documents using Tcl

LIB_DEPENDS=	xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS?=	dtplite:${PORTSDIR}/devel/tcllib

PORTDOCS=	README.xml html.xsl man.macros nroff.xsl tcldoc-1.0.dtd \
		tcldom.html tcldom.xml tclxml.css tclxml.html tclxml.xml \
		tclxslt.html tclxslt.xml transform.tcl txt.xsl

USES=		tcl
USE_XZ=		yes
XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_LDCONFIG?=	${PREFIX}/lib/Tclxml${PORTVERSION}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		XML_CONFIG="${XML_CONFIG}"
PLIST_SUB=	VER=${PORTVERSION}

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^TCLSH_ENV[[:blank:]]*=/,/[^\]$$/d' \
	${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} doc
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

check test: install
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

.include <bsd.port.mk>
