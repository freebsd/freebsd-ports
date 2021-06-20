# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	oslo.policy
PORTVERSION=	3.8.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo Policy library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oslo.config>=6.0.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.22.0:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.40.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
