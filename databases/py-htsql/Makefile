# Ports collection makefile for:	py-htsql
# Date created:			Dec 17, 2010
# Whom:				jpaetzel
#
# $FreeBSD$
#

PORTNAME=	htsql
PORTVERSION=	2.2.0b2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTSQL-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python HTSQL

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	HTSQL

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

post-patch:
	@${REINPLACE_CMD} -e 's|build/dist/egg|dist|g' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
