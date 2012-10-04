# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdbc
DISTVERSION=	1.0b17
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://tdbc.tcl.tk/index.cgi/tarball/
DISTFILES=	${PORTNAME:U}-${FOSSIL_HASH}.${EXTRACT_SUFX}?uuid=${FOSSIL_HASH}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The common database access interface for Tcl

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE ODBC

FOSSIL_HASH=	dc470dee3956a286ccdda1b7d9153950c282a2fe

USE_TCL=	86
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-${FOSSIL_HASH}.
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tcloo=${TCL_LIBDIR} \
		--prefix=${PREFIX} --exec-prefix=${PREFIX} \
		--with-tdbc=${WRKSRC}/tdbc --enable-threads
PLIST_SUB+=	VERSION=${DISTVERSION} \
		TCL_MAJ=${TCL_VER:R} \
		TCL_VER=${TCL_VER}

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
.if ${PORT_OPTIONS:MMYSQL}
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
.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
MODULES+=	tdbcodbc
PLIST_SUB+=	ODBC=""
MANN+=		tdbc_odbc.n
.else
PLIST_SUB+=	ODBC="@comment "
.endif

#
# PostgreSQL
#
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	client
MODULES+=	tdbcpostgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

#
# SQLite
#
.if ${PORT_OPTIONS:MSQLITE}
MODULES+=	tdbcsqlite3
PLIST_SUB+=	SQLITE="" \
		TCL_LIBDIR="${TCL_LIBDIR:S/${LOCALBASE}\///}"
MANN+=		tdbc_sqlite3.n
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

do-configure:
.for module in ${MODULES}
	@echo "================================="
	@echo "Configuring ${module}"
	cd ${WRKSRC}/${module} && ${SH} configure ${CONFIGURE_ARGS}
.endfor

post-configure:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|tdbcstub10b17|tdbcstub|g'

do-build:
.for module in ${MODULES}
	@echo "================================="
	@echo "Building ${module}"
	cd ${WRKSRC}/${module} && ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for module in ${MODULES}
	@echo "================================="
	@echo "Installing ${module}"
	cd ${WRKSRC}/${module} && ${MAKE} ${INSTALL_TARGET}
.endfor

test:
.for module in ${MODULES}
	@echo "================================="
	@echo "Testing ${module}"
	cd ${WRKSRC}/${module} && ${MAKE} test
.endfor

.include <bsd.port.mk>
