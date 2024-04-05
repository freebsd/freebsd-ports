PORTNAME=	usort
PORTVERSION=	1.0.8.post1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, safe import sorter
WWW=		https://usort.readthedocs.io/en/stable/ \
		https://github.com/facebook/usort

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=38.3.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=21.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=0.3.7:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moreorless>=0.3.0:devel/py-moreorless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stdlibs>=2021.4.1:devel/py-stdlibs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trailrunner>=1.0:devel/py-trailrunner@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
