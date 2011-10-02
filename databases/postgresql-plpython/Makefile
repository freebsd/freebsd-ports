# New ports collection makefile for:	PostgreSQL PL/Python
# Date created:		March 4, 2004
# Whom:			Dima Dorfman <dd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	1
CATEGORIES=	databases python
PKGNAMESUFFIX=	-plpython

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	A module for using Python to write SQL functions

RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

MASTERDIR=	${.CURDIR}/../postgresql${PGSQL_VER}-server

DEFAULT_PGSQL_VER?=84

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

USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-python

BUILD_DIRS=	src/pl/plpython
SLAVE_ONLY=	yes

POSTGRESQL_PORT=databases/postgresql${PGSQL_VER}-server

.include "${MASTERDIR}/Makefile"
