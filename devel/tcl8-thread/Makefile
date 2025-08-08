PORTNAME=	thread
PORTVERSION=	2.8.10
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/Tcl/8.6.15/
PKGNAMEPREFIX=	tcl8
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Scripting level thread extension for Tcl
WWW=		https://wiki.tcl.tk/2770

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		tcl:86,tea

DOCSDIR=	${PREFIX}/share/doc/${TCL_PKG}
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}

PLIST_SUB+=	VERSION="${PORTVERSION}"

INSTALL_TARGET=	install-binaries install-doc
TEST_TARGET=	test

OPTIONS_DEFINE=	DOCS GDBM LMDB
OPTIONS_DEFAULT=GDBM
GDBM_DESC=	Persistent shared variables using GDBM
LMDB_DESC=	Persistent shared variables using LMDB
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_WITH=	lmdb

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} "/INSTALL_LIBRARY=/s|'\$$| -s'|" \
	    ${WRKSRC}/tclconfig/tcl.m4

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
