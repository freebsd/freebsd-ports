# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htsql-pgsql
PORTVERSION=	2.3.3
PORTREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Database Query Language (PostgreSQL Backend for HTSQL)

LICENSE=	AGPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}htsql>2.3:databases/py-htsql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
