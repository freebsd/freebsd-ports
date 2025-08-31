PORTNAME=	taskflow
PORTVERSION=	5.12.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Taskflow structured state management library
WWW=		https://docs.openstack.org/taskflow/latest/ \
		https://github.com/openstack/taskflow

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}automaton>=1.9.0:devel/py-automaton@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=2.0.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.17.3:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futurist>=1.2.0:devel/py-futurist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema3>=3.2.0:devel/py-jsonschema3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.1.0,1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>=1.2.4:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=6.0.0:devel/py-tenacity@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DATABASE EVENTLET REDIS WORKERS
DATABASE_DESC=	Database support
EVENTLET_DESC=	Eventlet support
REDIS_DESC=	Redis support
WORKERS_DESC=	Worker support

DATABASE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0.8.10:databases/py-alembic@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.0:databases/py-psycopg2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pymysql>=0.7.6:databases/py-pymysql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.0.10:databases/py-sqlalchemy20@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy-utils>=0.30.11:databases/py-sqlalchemy-utils@${PY_FLAVOR}
EVENTLET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=4.0.0:databases/py-redis@${PY_FLAVOR}
WORKERS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kombu>=4.3.0:net/py-kombu@${PY_FLAVOR}

.include <bsd.port.mk>
