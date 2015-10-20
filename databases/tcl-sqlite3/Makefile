# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.9.1
CATEGORIES=	databases tcl
MASTER_SITES=	https://www.sqlite.org/2015/ http://www2.sqlite.org/2015/ http://www3.sqlite.org/2015/
PKGNAMEPREFIX=	tcl-
DISTNAME=	sqlite-autoconf-${PORTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	THREADS
OPTIONS_DEFAULT=	THREADS

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USES=		pkgconfig tcl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-Os
CFLAGS+=	`pkg-config --cflags sqlite3`
LDFLAGS+=	`pkg-config --libs sqlite3`
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-system-sqlite

THREADS_CONFIGURE_ENABLE=	threads

PLIST_FILES+=		lib/${PORTNAME}/libsqlite${PORTVERSION}.so lib/${PORTNAME}/pkgIndex.tcl
PORTEXAMPLES=		*

SUB_FILES=	example.tcl
SUB_LIST=	"TCLSH=${TCLSH}"

PLIST_FILES+=	man/mann/sqlite3.n.gz

post-patch:
	@${REINPLACE_CMD} -E 's/^(.*\$$\(PACKAGE_NAME\))\$$\(PACKAGE_VERSION\).*$$/\1${PORTVERSION:C/[^[:digit:]]*([[:digit:]]+).*/\1/}/' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libsqlite${PORTVERSION}.so
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
