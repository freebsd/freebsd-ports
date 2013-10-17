# Created by: Palle Girgensohn <girgen@partitur.se>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	4
CATEGORIES=	databases tcl
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Tcl to write SQL functions

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER}-server

BUILD_DEPENDS=	postgres:${POSTGRESQL_PORT}
RUN_DEPENDS=	postgres:${POSTGRESQL_PORT}
POSTGRESQL_PORT?=${PORTSDIR}/databases/postgresql${WANT_PGSQL_VER}-server

WANT_PGSQL_VER?=91

# you can use "make WITH_TCL_VER=84" or similar for your favourite tcl version
USE_TCL=	84+
CONFIGURE_ARGS=	--with-tcl --without-tk \
		--with-tclconfig="${TCL_LIBDIR}" \
		--with-includes="${TCL_INCLUDEDIR}"

CONFIGURE_ENV+=	TCLSH="${TCLSH}"
MAKE_ENV+=	TCL_INCDIR="${TCL_INCLUDEDIR}"

BUILD_DIRS=	src/backend src/pl/tcl
INSTALL_DIRS=	src/pl/tcl
SLAVE_ONLY=	yes
COMPONENT=	-pltcl

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
