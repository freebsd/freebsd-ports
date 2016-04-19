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

USES=		autoreconf tcl

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/thread${PORTVERSION}

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
