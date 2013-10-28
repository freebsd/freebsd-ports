# $FreeBSD$

PORTNAME=	postgresql
CATEGORIES=	databases python
PKGNAMESUFFIX?=	${DISTVERSION:R:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Python to write SQL functions

USE_PGSQL=	server

MASTERDIR=	${.CURDIR}/../postgresql${WANT_PGSQL_VER}-server

WANT_PGSQL_VER?=	90

USE_PYTHON?=	yes
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

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
