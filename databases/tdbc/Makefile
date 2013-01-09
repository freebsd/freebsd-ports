# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdbc
DISTVERSION=	1.0.0
CATEGORIES=	databases
MASTER_SITES=	SF/tcl/Tcl/8.6.0
DISTFILES=	${PORTNAME}${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	The common database access interface for Tcl

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE ODBC

USE_TCL=	86
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tcloo=${TCL_LIBDIR} \
		--prefix=${PREFIX} --exec-prefix=${PREFIX} \
		--with-tdbc=${WRKDIR}/tdbc${PORTVERSION} --enable-threads \
		--mandir=${PREFIX}/man
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
DISTFILES+=	${PORTNAME}mysql${PORTVERSION}${EXTRACT_SUFX}
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
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
DISTFILES+=	${PORTNAME}odbc${PORTVERSION}${EXTRACT_SUFX}
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
DISTFILES+=	${PORTNAME}postgres${PORTVERSION}${EXTRACT_SUFX}
MODULES+=	tdbcpostgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

#
# SQLite
#
.if ${PORT_OPTIONS:MSQLITE}
DISTFILES+=	${PORTNAME}sqlite3-${PORTVERSION}${EXTRACT_SUFX}
MODULES+=	tdbcsqlite3
PLIST_SUB+=	SQLITE="" \
		TCL_LIBDIR="${TCL_LIBDIR:S/${LOCALBASE}\///}"
MANN+=		tdbc_sqlite3.n
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-extract:
	if [ -d ${WRKDIR}/tdbcsqlite3-${PORTVERSION} ]; then \
	    ${MV} ${WRKDIR}/tdbcsqlite3-${PORTVERSION} ${WRKDIR}/tdbcsqlite3${PORTVERSION}; \
	fi

do-configure:
.for module in ${MODULES}
	@echo "================================="
	@echo "Configuring ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SH} configure ${CONFIGURE_ARGS}
.endfor

post-configure:
	${FIND} ${WRKDIR} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|tdbcstub100|tdbcstub|g'

do-build:
.for module in ${MODULES}
	@echo "================================="
	@echo "Building ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for module in ${MODULES}
	@echo "================================="
	@echo "Installing ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${MAKE} ${INSTALL_TARGET}
.endfor

test:
.for module in ${MODULES}
	@echo "================================="
	@echo "Testing ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${MAKE} test
.endfor

.include <bsd.port.mk>
