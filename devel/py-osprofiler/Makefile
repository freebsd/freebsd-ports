# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	osprofiler
PORTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Profiler Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.13:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
