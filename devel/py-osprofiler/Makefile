PORTNAME=	osprofiler
PORTVERSION=	4.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Profiler Library
WWW=		https://docs.openstack.org/osprofiler/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.26.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.2:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ELASTICSEARCH MESSAGING MONGO OTLP REDIS SQLALCHEMY
ELASTICSEARCH_DESC=	Elasticsearch driver support
MESSAGING_DESC=	Messaging driver support
MONGO_DESC=	MongoDB driver support
OTLP_DESC=	OTLP exporter support
REDIS_DESC=	Redis driver support
SQLALCHEMY_DESC=SQLAlchemy driver support

ELASTICSEARCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch>=2.0.0:textproc/py-elasticsearch@${PY_FLAVOR}
MESSAGING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oslo.messaging>=14.1.0:devel/py-oslo.messaging@${PY_FLAVOR}
MONGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.2:databases/py-pymongo@${PY_FLAVOR}
OTLP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>=1.16.0:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.16.0:devel/py-opentelemetry-sdk@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.10.0:databases/py-redis@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.0:databases/py-sqlalchemy20@${PY_FLAVOR}

.include <bsd.port.mk>
