# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	osprofiler
PORTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Profiler Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.13:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
