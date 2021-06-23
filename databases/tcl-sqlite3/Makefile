PORTNAME=	sqlite3
PORTVERSION=	3.34.1
CATEGORIES=	databases tcl
MASTER_SITES=	https://www.sqlite.org/2021/ \
		https://www2.sqlite.org/2021/ \
		https://www3.sqlite.org/2021/
PKGNAMEPREFIX=	tcl-
DISTNAME=	sqlite-autoconf-${PORTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQLite extension for Tcl using the Tcl Extension Architecture (TEA)

LICENSE=	PD

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		pkgconfig tcl:tea
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-system-sqlite

CFLAGS+=	`pkg-config --cflags sqlite3`
LDFLAGS+=	`pkg-config --libs sqlite3`

SUB_FILES=	example.tcl
SUB_LIST=	"TCLSH=${TCLSH}"

WRKSRC=		${WRKDIR}/${DISTNAME}/tea

PLIST_FILES=	lib/${PORTNAME}/libsqlite${PORTVERSION}.so \
		lib/${PORTNAME}/pkgIndex.tcl \
		man/mann/sqlite3.n.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES THREADS
OPTIONS_DEFAULT=	THREADS

THREADS_CONFIGURE_ENABLE=	threads

post-patch:
	@${REINPLACE_CMD} -E 's/^(.*\$$\(PACKAGE_NAME\))\$$\(PACKAGE_VERSION\).*$$/\1${PORTVERSION:C/[^[:digit:]]*([[:digit:]]+).*/\1/}/' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libsqlite${PORTVERSION}.so
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
