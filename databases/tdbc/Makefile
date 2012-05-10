# New ports collection Makefile for:	tdbc
# Date created:				16 March 2012
# Whom:					Pietro Cerutti <gahr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tdbc
DISTVERSION=	1.0b17
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://tdbc.tcl.tk/index.cgi/tarball/
DISTFILES=	${PORTNAME:U}-${FOSSIL_HASH}.${EXTRACT_SUFX}?uuid=${FOSSIL_HASH}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The common database access interface for Tcl

OPTIONS=	MYSQL  "Build MySQL driver" off \
		UODBC  "Build ODBC driver (unixODBC)" off \
		IODBC  "Build ODBC driver (iODBC)" off \
		PGSQL  "Build PostgreSQL driver" off \
		SQLITE "Build SQLite driver" off

FOSSIL_HASH=	9972d7cf7d10b55157773ba027e54713d53e4cee

USE_TCL=	86
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-${FOSSIL_HASH}.
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tcloo=${TCL_LIBDIR} \
		--prefix=${PREFIX} --exec-prefix=${PREFIX} \
		--with-tdbc=${WRKSRC}/tdbc --enable-threads
PLIST_SUB+=	VERSION=${DISTVERSION}
SUB_FILES+=	pkgIndex.tcl
SUB_LIST+=	DISTVERSION=${DISTVERSION}

MODULES=	tdbc

MAN3=	Tdbc_Init.3
MANN=	tdbc.n \
	tdbc_connection.n \
	tdbc_mapSqlState.n \
	tdbc_resultset.n \
	tdbc_statement.n \
	tdbc_tokenize.n

.include <bsd.port.options.mk>

#
# MySQL
#
.if defined(WITH_MYSQL)
MODULES+=	tdbcmysql
PLIST_SUB+=	MYSQL=""
MANN+=		tdbc_mysql.n
USE_MYSQL=	client
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

#
# ODBC
#
.if defined(WITH_UODBC) && defined(WITH_IODBC)
IGNORE=	please select either UODBC or IODBC, but not both
.endif

.if defined(WITH_UODBC) && !defined(WITH_IODBC)
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.endif

.if defined(WITH_IODBC) && !defined(WITH_UODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif

.if defined(WITH_UODBC) || defined(WITH_IODBC)
MODULES+=	tdbcodbc
PLIST_SUB+=	ODBC=""
MANN+=		tdbc_odbc.n
.else
PLIST_SUB+=	ODBC="@comment "
.endif

#
# PostgreSQL
#
.if defined(WITH_PGSQL)
USE_PGSQL=	client
MODULES+=	tdbcpostgres
PLIST_SUB+=	PGSQL=""
MANN+=		tdbc_postgres.n
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

#
# SQLite
#
.if defined(WITH_SQLITE)
MODULES+=	tdbcsqlite3
PLIST_SUB+=	SQLITE="" \
		TCL_LIBDIR="${TCL_LIBDIR:S/${LOCALBASE}\///}"
MANN+=		tdbc_sqlite3.n
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

do-configure:
.for module in ${MODULES}
	cd ${WRKSRC}/${module} && ${SH} configure ${CONFIGURE_ARGS}
.endfor

post-configure:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|tdbcstub10b17|tdbcstub|g'

do-build:
.for module in ${MODULES}
	cd ${WRKSRC}/${module} && ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for module in ${MODULES}
	cd ${WRKSRC}/${module} && ${MAKE} ${INSTALL_TARGET}
.endfor
.if defined(WITH_SQLITE)
	${INSTALL_DATA} ${WRKDIR}/pkgIndex.tcl ${TCL_LIBDIR:S/${LOCALBASE}/${PREFIX}/}/tdbc
.endif

test:
.for module in ${MODULES}
	cd ${WRKSRC}/${module} && ${MAKE} test
.endfor

.include <bsd.port.mk>
