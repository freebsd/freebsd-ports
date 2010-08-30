# New ports collection makefile for:	PostgreSQL PL/Tcl
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	3
CATEGORIES=	databases tcl
PKGNAMESUFFIX=	-pltcl

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A module for using Tcl to write SQL functions

MASTERDIR=	${.CURDIR}/../../databases/postgresql${PGSQL_VER}-server

RUN_DEPENDS=	postgres:${MASTERDIR}

DEFAULT_PGSQL_VER?=82

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	/usr/local
SED?=		/usr/bin/sed

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | ${SED} -n 's/.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

# you can use "make WITH_TCL_VER=84" or similar for your favourite tcl version
USE_TCL=	84+
CONFIGURE_ARGS=	--with-tcl --without-tk \
		--with-tclconfig="${TCL_LIBDIR}" \
		--with-includes="${TCL_INCLUDEDIR}"

CONFIGURE_ENV+=	TCLSH="${TCLSH}"
MAKE_ENV+=	TCL_INCDIR="${TCL_INCLUDEDIR}"

BUILD_DIRS=	src/pl/tcl
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
