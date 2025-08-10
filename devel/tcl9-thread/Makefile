PORTNAME=	thread
PORTVERSION=	3.0.2
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/Tcl/9.0.2
PKGNAMEPREFIX=	tcl9-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Scripting level thread extension for Tcl 9
WWW=		https://wiki.tcl.tk/2770

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		tcl:90,tea

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
	@${FIND} ${WRKSRC}/doc/man -name "*.n" | \
		while read f; \
		do \
			${MV} "$${f}" "$$(echo $${f} | ${SED} 's|.n$$|.${TCL_PKG_LIB_PREFIX}.n|')"; \
		done

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
