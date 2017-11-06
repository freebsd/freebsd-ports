# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	osc-lib
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStackClient plugin library support

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.16.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}cliff>=2.3.0:devel/py-cliff \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.0:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}os-client-config>=1.22.0:devel/py-os-client-config \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
