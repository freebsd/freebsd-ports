# New ports collection makefile for:	PostgreSQL PL/Tcl
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	databases tcl${TCLVERSION:S/.//}
PKGNAMESUFFIX=	-pltcl

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A module for using Tcl to write SQL functions

MASTERDIR=	${.CURDIR}/../postgresql${PGSQL_VER}-server

RUN_DEPENDS=	postgres:${MASTERDIR}
LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//}

DEFAULT_PGSQL_VER?=74

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	${DESTDIR}/usr/local
SED?=		/usr/bin/sed

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | ${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.4
CONFIGURE_ARGS=	--with-tcl --without-tk \
		--with-tclconfig="${TCLCONFIG}" \
		--with-includes="${TCL_INCDIR}"

TCL_INCDIR=	${LOCALBASE}/include/tcl${TCLVERSION}
TCLCONFIG=	${LOCALBASE}/lib/tcl${TCLVERSION}
MAKE_ENV+=	TCL_INCDIR=${TCL_INCDIR}

BUILD_DIRS=	src/pl/tcl
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
