PORTNAME=	scikit-build
DISTVERSION=	0.16.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build system generator for Python C/C++/Fortran/Cython extensions
WWW=		https://scikit-build.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.32.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}build>=0.7:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path.py>=11.5.0:devel/py-path.py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 tests fail, 4 errors, see https://github.com/scikit-build/scikit-build/issues/791

NO_ARCH=	yes

.include <bsd.port.mk>
