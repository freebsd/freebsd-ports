PORTNAME=	cibuildwheel # doesn't fully support FreeBSD
DISTVERSION=	2.23.2
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build Python wheels on CI with minimal configuration
WWW=		https://cibuildwheel.pypa.io/en/stable \
		https://github.com/pypa/cibuildwheel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bashlex>=0.13:devel/py-bashlex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bracex>0:textproc/py-bracex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dependency-groups>=1.2:devel/py-dependency-groups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

.include <bsd.port.mk>
