# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.concurrency
PORTVERSION=	3.15.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Oslo Concurrency library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enum34>=0:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.7:devel/py-fasteners

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
