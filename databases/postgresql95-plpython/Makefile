# $FreeBSD$

PORTNAME=	postgresql
CATEGORIES=	databases python
PORTREVISION=	1
PKGNAMESUFFIX?=	${WANT_PGSQL_VER:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Python to write SQL functions

USES+=		pgsql:${WANT_PGSQL_VER} ${WANT_PYTHON_USE}
WANT_PGSQL=	server

MASTERDIR=	${.CURDIR}/../postgresql${WANT_PGSQL_VER:S/.//}-server

WANT_PGSQL_VER?=	9.5
WANT_PYTHON_USE?=	python

CONFIGURE_ARGS=	--with-python
COMPONENT=	-plpython

BUILD_DIRS=	src/backend src/pl/plpython
INSTALL_DIRS=	src/pl/plpython
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
