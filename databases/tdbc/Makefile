# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tdbc
DISTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	SF/tcl/Tcl/8.6.2
DISTFILES=	${PORTNAME}${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Common database access interface for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKDIR}/${PORTNAME}${PORTVERSION}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE ODBC

USES=		tcl:86
USE_LDCONFIG=	yes
MAKE_ENV+=	DESTDIR=${STAGEDIR}
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-tcloo=${TCL_LIBDIR} \
		--prefix=${PREFIX} --exec-prefix=${PREFIX} \
		--with-tdbc=${WRKDIR}/tdbc${PORTVERSION} --enable-threads \
		--mandir=${PREFIX}/man
PLIST_SUB+=	VERSION=${DISTVERSION} \
		TCL_MAJ=${TCL_VER:R} \
		TCL_VER=${TCL_VER}

MODULES=	tdbc

.include <bsd.port.options.mk>

#
# MySQL
#
.if ${PORT_OPTIONS:MMYSQL}
DISTFILES+=	${PORTNAME}mysql${PORTVERSION}${EXTRACT_SUFX}
MODULES+=	tdbcmysql
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	client
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

#
# ODBC
#
.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
DISTFILES+=	${PORTNAME}odbc${PORTVERSION}${EXTRACT_SUFX}
MODULES+=	tdbcodbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

#
# PostgreSQL
#
.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
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
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

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
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SETENV} ${CONFIGURE_ENV} ${SH} configure ${CONFIGURE_ARGS}
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

test:
.for module in ${MODULES}
	@echo "================================="
	@echo "Testing ${module}"
	cd ${WRKDIR}/${module}${PORTVERSION} && ${SETENV} ${MAKE_ENV} ${MAKE} test
.endfor

.include <bsd.port.mk>
