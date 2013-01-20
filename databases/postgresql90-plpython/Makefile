# $FreeBSD$

PORTNAME=	postgresql
CATEGORIES=	databases python
PKGNAMESUFFIX=	${WANT_PGSQL_VER}-plpython

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Python to write SQL functions

USE_PGSQL=	server

MASTERDIR=	${.CURDIR}/../postgresql${WANT_PGSQL_VER}-server

WANT_PGSQL_VER?=	90

USE_PYTHON?=	yes
PYTHON_MAJOR_VER=	${PYTHON_VER:R}
CONFIGURE_ARGS=	--with-python
PLIST_SUB=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

.if ${PYTHON_MAJOR_VER} == 3
PLIST_SUB+=	PYTHON3=""
.else
PLIST_SUB+=	PYTHON3="@comment "
.endif

BUILD_DIRS=	src/backend src/pl/plpython
INSTALL_DIRS=	src/pl/plpython
SLAVE_ONLY=	yes

.include "${MASTERDIR}/Makefile"
