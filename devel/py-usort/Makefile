PORTNAME=	usort
PORTVERSION=	1.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, safe import sorter
WWW=		https://usort.readthedocs.io/en/stable/ \
		https://github.com/facebook/usort

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=21.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=0.3.7:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moreorless>=0.3.0:devel/py-moreorless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stdlibs>=2021.4.1:devel/py-stdlibs@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trailrunner>=1.0<2.0:devel/py-trailrunner@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
