# $FreeBSD$

PORTNAME=	oslo.utils
PORTVERSION=	3.21.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Oslo Utility library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>0:devel/py-debtcollector@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.3:devel/py-monotonic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
