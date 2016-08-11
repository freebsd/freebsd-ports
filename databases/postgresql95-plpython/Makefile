# $FreeBSD$

PORTNAME=	postgresql
CATEGORIES=	databases python
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Python to write SQL functions

USES+=		pgsql:${WANT_PGSQL_VER} ${WANT_PYTHON_USE}
WANT_PGSQL=	server

MASTERDIR=	${.CURDIR}/../postgresql${WANT_PGSQL_VER:S/.//}-server

WANT_PGSQL_VER?=	9.5
WANT_PYTHON_USE?=	python

CONFIGURE_ARGS=	--with-python
COMPONENT=	-plpython

.if defined(PYTHON_VER) && ${PYTHON_VER:R} == 3
PLIST_SUB+=	PYTHON2="@comment " PYTHON3=""
.else
PLIST_SUB+=	PYTHON2="" PYTHON3="@comment "
.endif

BUILD_DIRS=	src/backend src/pl/plpython
INSTALL_DIRS=	src/pl/plpython
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
