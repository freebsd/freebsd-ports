# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.8.0.2
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.sqlite.org/2013/ http://www2.sqlite.org/2013/ http://www3.sqlite.org/2013/
PKGNAMEPREFIX=	tcl-
DISTNAME=	sqlite-autoconf-3080002

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	EXAMPLES

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

USES=		pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_TCL=	84+

CFLAGS+=	`pkg-config --cflags --libs sqlite3`
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-system-sqlite

PLIST_DIRS+=		lib/sqlite3
PLIST_FILES+=		lib/sqlite3/libsqlite.so.1 lib/sqlite3/pkgIndex.tcl
PORTEXAMPLES=		*

SUB_FILES=	example.tcl
SUB_LIST=	"TCLSH=${TCLSH}"

MANN=	sqlite3.n

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's,\(^PKG_DIR.*\)$$(PACKAGE_VERSION),\13,g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
