# New ports collection makefile for:	PostgreSQL PL/Python
# Date created:		March 4, 2004
# Whom:			Dima Dorfman <dd@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	databases python
PKGNAMESUFFIX=	-plpython

MAINTAINER=	dd@FreeBSD.org
COMMENT=	A module for using Python to write SQL functions

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include "../../${POSTGRESQL_PORT}/Makefile"

RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

USE_PYTHON=	yes

MAKE_ARGS+=	-C src/pl/plpython
CONFIGURE_ARGS=	--with-python

.include <bsd.port.mk>
