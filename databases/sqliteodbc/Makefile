PORTNAME=	sqliteodbc
PORTVERSION=	0.99991
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/sqliteodbc/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	ODBC driver for SQLite 3
WWW=		http://www.ch-werner.de/sqliteodbc/

LICENSE=	SQLITEODBC
LICENSE_NAME=	sqliteodbc own licensing terms (BSD style)
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libodbc.so:databases/unixODBC

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sqlite4
USE_LDCONFIG=	yes
USES=		cpe libtool

CPE_VENDOR=	sqliteodbc_project

PLIST_SUB+=	VER="${PORTVERSION}"

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-sqlite2"
PLIST_SUB+=	SQLITE2="" SQLITE3="@comment "
USES+=		sqlite:2
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE} \
			--with-sqlite3=/tmp
.else
PLIST_SUB+=	SQLITE2="@comment " SQLITE3=""
USES+=		sqlite:3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE} \
			--with-sqlite=/tmp
LIB_DEPENDS+=	libxml2.so:textproc/libxml2
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/.libs/libsqlite*${PORTVERSION}.so

.include <bsd.port.mk>
