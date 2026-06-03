PORTNAME=	ninja
DISTVERSION=	1.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package providing the Ninja build tool
WWW=		https://github.com/scikit-build/ninja-python-distributions

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE_Apache_20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=22.3:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	ninja:devel/ninja

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist

MAKE_ENV+=	NINJA_PYTHON_DIST_ALLOW_NINJA_DEP=1

.include <bsd.port.mk>
