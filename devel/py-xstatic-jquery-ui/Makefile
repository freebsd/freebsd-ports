PORTNAME=	xstatic-jquery-ui
PORTVERSION=	1.13.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_jquery_ui-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jquery-ui ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://github.com/xstatic-py/xstatic-jquery_ui

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic-jquery>=0:devel/py-xstatic-jquery@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
