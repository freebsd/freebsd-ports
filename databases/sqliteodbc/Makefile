# $FreeBSD$

PORTNAME=	sqliteodbc
PORTVERSION=	0.999
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/sqliteodbc/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	ODBC driver for SQLite 2 and 3

LICENSE=	SQLITEODBC
LICENSE_NAME=	sqliteodbc own licensing terms (BSD style)
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sqlite4
USE_LDCONFIG=	yes
USES=		libtool

PLIST_SUB+=	VER="${PORTVERSION}"

OPTIONS_DEFINE=	SQLITE SQLITE3
OPTIONS_DEFAULT=	SQLITE3

OPTIONS_SUB=	yes
SQLITE_LIB_DEPENDS=	libsqlite.so:${PORTSDIR}/databases/sqlite2
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--with-sqlite=/tmp
SQLITE3_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
			libxml2.so:${PORTSDIR}/textproc/libxml2
SQLITE3_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}
SQLITE3_CONFIGURE_OFF=	--with-sqlite3=/tmp

post-build:
	@${STRIP_CMD} ${WRKSRC}/.libs/libsqlite*${PORTVERSION}.so

.include <bsd.port.mk>
