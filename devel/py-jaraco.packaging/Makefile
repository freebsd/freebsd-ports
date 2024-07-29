PORTNAME=	jaraco.packaging
PORTVERSION=	10.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jaraco_packaging-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools to supplement packaging Python releases
WWW=		https://github.com/jaraco/jaraco.packaging

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}domdf-python-tools>=0:devel/py-domdf-python-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=0:devel/py-jaraco.context@${PY_FLAVOR}
# build[virtualenv]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}virtualenv>=20.0.35:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SPHINX
SPHINX_DESC=	Sphinx extension (jaraco.packaging.sphinx)

SPHINX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

.include <bsd.port.mk>
