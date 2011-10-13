# Ports collection makefile for:	py-htsql
# Date created:			Dec 17, 2010
# Whom:				jpaetzel
#
# $FreeBSD$
#

PORTNAME=	htsql
PORTVERSION=	2.2.0b2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTSQL-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python HTSQL

USE_PYTHON=	2.5-2.7
PLIST_SUB= PYTHON_VER=${PYTHON_VER}
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	HTSQL
PYDISTUTILS_NOEGGINFO=	yes

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson

.include <bsd.port.mk>
