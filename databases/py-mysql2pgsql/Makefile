# $FreeBSD$

PORTNAME=	mysql2pgsql
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Tool for migrating/converting from MySQL to PostgreSQL

LICENSE=	MIT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.2:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	philipsoutham
GH_PROJECT=	py-${PORTNAME}

.include <bsd.port.mk>
