PORTNAME=	sqlite3
DISTVERSION=	3.50.4
CATEGORIES=	databases tcl
MASTER_SITES=	SF/tcl/Tcl/8.6.17
PKGNAMEPREFIX=	tcl-
DISTNAME=	${TCL_PKG}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)
WWW=		https://www.sqlite.org/

LICENSE=	PD

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		tcl:tea

MAKE_ENV+=	STRIPPROG=${STRIP_CMD}

TCL_PKG=	${PORTNAME:S/3//}${DISTVERSION}
PLIST_FILES=	bin/sqlite3_analyzer \
		lib/sqlite3/lib${TCL_PKG_LIB_PREFIX}${TCL_PKG}.so \
		lib/sqlite3/pkgIndex.tcl \
		share/man/mann/sqlite3.n.gz

post-patch:
	@${REINPLACE_CMD} -E 's/^(.*\$$\(PACKAGE_NAME\))\$$\(PACKAGE_VERSION\).*$$/\1${PORTVERSION:C/[^[:digit:]]*([[:digit:]]+).*/\1/}/' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/lib${TCL_PKG_LIB_PREFIX}sqlite${PORTVERSION}.so

.include <bsd.port.mk>
