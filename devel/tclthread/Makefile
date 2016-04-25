# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thread
PORTVERSION=	2.7.3
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/Thread%20Extension/${PORTVERSION}
PKGNAMEPREFIX=	tcl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Scripting level thread extension for Tcl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		autoreconf tcl:tea

DOCSDIR=	${PREFIX}/share/doc/${TCL_PKG}
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}

PLIST_SUB+=	VERSION="${PORTVERSION}"

INSTALL_TARGET=	install-binaries install-libraries install-doc
TEST_TARGET=	test

OPTIONS_DEFINE=	GDBM DOCS
OPTIONS_DEFAULT=GDBM
GDBM_DESC=	Persistent shared variables using GDBM
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} "/INSTALL_LIBRARY=/s|'\$$| -s'|" \
	    ${WRKSRC}/tclconfig/tcl.m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in thread.html tpool.html tsv.html ttrace.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${FILE} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
