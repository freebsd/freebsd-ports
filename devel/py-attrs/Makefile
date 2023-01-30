PORTNAME=	attrs
PORTVERSION=	22.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python attributes without boilerplate
WWW=		https://github.com/python-attrs/attrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# devel/py-pytest-xdist[psutil]: sysutils/py-psutil
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.971:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pympler>=0:devel/py-pympler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest-mypy-plugins>=0:devel/py-pytest-mypy-plugins@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
