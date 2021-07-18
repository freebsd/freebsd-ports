PORTNAME=	postgresql
CATEGORIES=	databases python
# Keep the ?=, it is used as master by the other plpython ports.
PORTREVISION?=	0
PKGNAMESUFFIX?=	${WANT_PGSQL_VER:S/.//}${COMPONENT}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Module for using Python to write SQL functions

USES+=		pgsql:${WANT_PGSQL_VER} ${WANT_PYTHON_USE}
WANT_PGSQL=	server

MASTERDIR=	${.CURDIR}/../postgresql${WANT_PGSQL_VER:S/.//}-server

WANT_PGSQL_VER?=	12
WANT_PYTHON_USE?=	python

CONFIGURE_ARGS=	--with-python
COMPONENT=	-plpython

BUILD_DIRS=	src/backend ${INSTALL_DIRS}
INSTALL_DIRS?=	src/pl/plpython contrib/hstore_plpython contrib/jsonb_plpython contrib/ltree_plpython
SLAVE_ONLY=	yes

# this port fails to build in parallel
MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
