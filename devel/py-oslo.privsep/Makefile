# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.privsep
PORTVERSION=	1.14.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Openstack library for privilege separation

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enum34>=0:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.0:devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
