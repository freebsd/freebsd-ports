# $FreeBSD$

PORTNAME=	oslo.utils
PORTVERSION=	3.13.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Oslo Utility library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>0:devel/py-debtcollector \
		${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.3:devel/py-monotonic \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
