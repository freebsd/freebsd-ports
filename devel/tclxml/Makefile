# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	tclxml
PORTVERSION=	3.3
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

USES=		tcl tar:xz
XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_LDCONFIG?=	${PREFIX}/lib/Tclxml${PORTVERSION}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		XML_CONFIG="${XML_CONFIG}"
PLIST_SUB=	VER=${PORTVERSION}

OPTIONS_DEFINE=	DOCS
MAKE_ENV+=	TCLLIBPATH=${STAGEDIR}/usr/local/lib

post-patch:
	@${REINPLACE_CMD} -e '/^TCLSH_ENV[[:blank:]]*=/,/[^\]$$/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/FreeBSD-\*/FreeBSD-*|DragonFly-*/g' \
		${WRKSRC}/configure

post-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} doc)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

check test: install
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
