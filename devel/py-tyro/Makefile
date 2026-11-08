PORTNAME=	tyro
DISTVERSION=	1.0.16
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pr9000@tutamail.com
COMMENT=	CLI interfaces & config objects, from types
WWW=		https://github.com/brentyi/tyro

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.16:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>=4.0.0:devel/py-typeguard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=21.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.5.2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-collections>=0.1.0:misc/py-ml-collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.18.6:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}omegaconf>=2.2.2:devel/py-omegaconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>=1.5.6:devel/py-shtab@${PY_FLAVOR} \
		bash:shells/bash

# FIXME Add port for TEST_DEPENDS
# ${PYTHON_PKGNAMEPREFIX}universal-pathlib>=0.2.0:devel/py-universal-pathlib@${PY_FLAVOR}

# Officially: 3.8-3.14
USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
