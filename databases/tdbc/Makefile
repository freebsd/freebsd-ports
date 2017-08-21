# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdbc
DISTVERSION=	1.0.5
CATEGORIES=	databases
MASTER_SITES=	SF/tcl/Tcl/8.6.7
DISTFILES=	${PORTNAME}${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Common database access interface for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKDIR}/${PORTNAME}${PORTVERSION}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE ODBC
OPTIONS_DEFAULT=MYSQL PGSQL SQLITE ODBC
OPTIONS_SUB=	yes

USES=		tcl:86,tea
USE_LDCONFIG=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}
CONFIGURE_ARGS+=--enable-threads \
		--mandir=${PREFIX}/man \
		--includedir=${PREFIX}/include/tdbc
PLIST_SUB+=	VERSION=${DISTVERSION} \
		TCL_MAJ=${TCL_VER:R} \
		TCL_VER=${TCL_VER}

MODULES=	tdbc

# TDBC (code)
tdbc_CONFIGURE_ARGS=	--with-tcloo=${TCL_LIBDIR}

# MySQL
MYSQL_VARS=		MODULES+=tdbcmysql
MYSQL_USES=		mysql:client
MYSQL_DISTFILES=	${PORTNAME}mysql${PORTVERSION}${EXTRACT_SUFX}

# ODBC
ODBC_VARS=		MODULES+=tdbcodbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_DISTFILES=		${PORTNAME}odbc${PORTVERSION}${EXTRACT_SUFX}
tdbcodbc_CONFIGURE_ARGS=--with-tdbc=${WRKDIR}/tdbc${PORTVERSION}

# PostgreSQL
PGSQL_VARS=		MODULES+=tdbcpostgres
PGSQL_USES=		pgsql
PGSQL_DISTFILES=	${PORTNAME}postgres${PORTVERSION}${EXTRACT_SUFX}

# SQLite
SQLITE_VARS=		MODULES+=tdbcsqlite3
SQLITE_DISTFILES=	${PORTNAME}sqlite3-${PORTVERSION}${EXTRACT_SUFX}
SQLITE_PLIST_SUB=	TCL_LIBDIR="${TCL_LIBDIR:S/${LOCALBASE}\///}"
SQLITE_RUN_DEPENDS=	${LOCALBASE}/lib/sqlite3/pkgIndex.tcl:databases/tcl-sqlite3

.include <bsd.port.options.mk>

post-extract:
	if [ -d ${WRKDIR}/tdbcsqlite3-${PORTVERSION} ]; then \
	    ${MV} ${WRKDIR}/tdbcsqlite3-${PORTVERSION} ${WRKDIR}/tdbcsqlite3${PORTVERSION}; \
	fi

post-patch:
	${FIND} ${WRKDIR} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
	    -e '/^DESTDIR/s|=|?=|' \
	    -e '/^INSTALL_PROGRAM/s|$$| -s|' \
	    -e '/^INSTALL_LIBRARY/s|$$| -s|'

do-configure:
.for module in ${MODULES}
	@echo "================================="
	@echo "Configuring ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && \
	    ${SETENV} ${CONFIGURE_ENV} ${SH} configure \
	    ${CONFIGURE_ARGS} ${${module}_CONFIGURE_ARGS}

.endfor

post-configure:
	${FIND} ${WRKDIR} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|tdbcstub100|tdbcstub|g'

do-build:
.for module in ${MODULES}
	@echo "================================="
	@echo "Building ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for module in ${MODULES}
	@echo "================================="
	@echo "Installing ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
.endfor

do-test:
.for module in ${MODULES}
	@echo "================================="
	@echo "Testing ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SETENV} ${MAKE_ENV} ${MAKE} test
.endfor

.include <bsd.port.mk>
