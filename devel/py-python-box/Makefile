PORTNAME=	python-box
DISTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	lazeraman@gmail.com
COMMENT=	Python dictionaries with advanced dot notation access
WWW=		https://github.com/cdgriffith/Box

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.19.1:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toon-format>=0:textproc/py-toon-format@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=0:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

OPTIONS_DEFINE=	MSGPACK PYYAML TOML TOMLI YAML
MSGPACK_DESC=	MessagePack serialization support
PYYAML_DESC=	PyYAML format or parser support
TOMLI_DESC=	TOMLI format or parser support

MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR}
PYYAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TOMLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR}
TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.19.1:devel/py-ruamel.yaml@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/box/*.so

.include <bsd.port.mk>
