PORTNAME=	python-box
DISTVERSION=	7.4.1
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
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.19.1:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toon-format>=0:textproc/py-toon-format@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

OPTIONS_DEFINE=	MSGPACK TOML YAML
MSGPACK_DESC=	MessagePack serialization support

MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR}
TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.19.1:devel/py-ruamel.yaml@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/box/*.so

.include <bsd.port.mk>
