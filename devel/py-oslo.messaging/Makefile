# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.messaging
PORTVERSION=	5.12.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Oslo Messaging API

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}futures>=3.0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying \
		${PYTHON_PKGNAMEPREFIX}pika-pool>=0.1.3:devel/py-pika-pool \
		${PYTHON_PKGNAMEPREFIX}pika>=0.10.0:devel/py-pika \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.17.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic \
		${PYTHON_PKGNAMEPREFIX}kombu>=3.0.25:net/py-kombu \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}futurist>=0:devel/py-futurist \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector \
		${PYTHON_PKGNAMEPREFIX}cachetools>=1.1.0:devel/py-cachetools \
		${PYTHON_PKGNAMEPREFIX}amqp>=0:net/py-amqp \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
