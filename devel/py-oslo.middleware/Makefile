# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.middleware
PORTVERSION=	3.20.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Oslo Middleware library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
