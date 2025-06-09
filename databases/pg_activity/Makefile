PORTNAME=	pg_activity
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Htop like application for PostgreSQL server activity monitoring
WWW=		https://github.com/dalibo/pg_activity

LICENSE=	PostgreSQL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blessed>=0:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=20.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${PY_FLAVOR}

USES=		python

OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	dalibo

USE_PYTHON=	autoplist concurrent optsuffix pep517

.include <bsd.port.mk>
