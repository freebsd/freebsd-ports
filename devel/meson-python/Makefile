PORTNAME=	meson-python
DISTVERSION=	0.16.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	meson_python-${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Meson Python build backend (PEP-517)
WWW=		https://github.com/mesonbuild/meson-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0.19.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.7.1:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PY_TOMLI}
RUN_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0.19.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.7.1:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		git:devel/git

USES=		python
USE_PYTHON=	autoplist cython_test concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
