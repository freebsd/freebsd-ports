# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.messaging
PORTVERSION=	5.17.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Oslo Messaging API

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pika-pool>=0.1.3:devel/py-pika-pool@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pika>=0.10.0:devel/py-pika@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kombu>=3.0.25:net/py-kombu@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futurist>=0:devel/py-futurist@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=1.1.0:devel/py-cachetools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}amqp>=0:net/py-amqp@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=3.2.1:devel/py-tenacity@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
