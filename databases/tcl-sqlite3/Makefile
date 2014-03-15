# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.8.4.1
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.sqlite.org/2014/ http://www2.sqlite.org/2014/ http://www3.sqlite.org/2014/
PKGNAMEPREFIX=	tcl-
DISTNAME=	sqlite-autoconf-3080401

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	EXAMPLES

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USES=		pkgconfig tcl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	`pkg-config --cflags sqlite3`
LDFLAGS+=	`pkg-config --libs sqlite3`
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-system-sqlite

PLIST_DIRS+=		lib/${PORTNAME}
PLIST_FILES+=		lib/${PORTNAME}/libsqlite${PORTVERSION:S/.//g}.so.1 lib/${PORTNAME}/pkgIndex.tcl
PORTEXAMPLES=		*

SUB_FILES=	example.tcl
SUB_LIST=	"TCLSH=${TCLSH}"

PLIST_FILES+=	man/mann/sqlite3.n.gz

post-patch:
	@${REINPLACE_CMD} -E 's/^(.*\$$\(PACKAGE_NAME\))\$$\(PACKAGE_VERSION\).*$$/\1${PORTVERSION:C/[^[:digit:]]*([[:digit:]]+).*/\1/}/' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libsqlite${PORTVERSION:S/.//g}.so.1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
