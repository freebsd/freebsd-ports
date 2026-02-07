PORTNAME=	cattrs
PORTVERSION=	25.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Composable complex class support for attrs and dataclasses
WWW=		https://catt.rs/en/stable/ \
		https://github.com/python-attrs/cattrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=24.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CBOR2 MSGPACK MSGSPEC ORJSON PYYAML TOMLKIT UJSON
CBOR2_DESC=	cobr2 serialization support
MSGPACK_DESC=	msgpack serialization support
MSGSPEC_DESC=	msgspec serialization support
ORJSON_DESC=	orjson serialization support
PYYAML_DESC=	PyYAML serialization support
TOMLKIT_DESC=	tomlkit serialization support
UJSON_DESC=	UltraJSON serialization support

CBOR2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cbor2>=5.4.6:devel/py-cbor2@${PY_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.5:devel/py-msgpack@${PY_FLAVOR}
MSGSPEC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgspec>=0.19.0:devel/py-msgspec@${PY_FLAVOR}
ORJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orjson>=3.10.7:devel/py-orjson@${PY_FLAVOR}
PYYAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}
TOMLKIT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.8:textproc/py-tomlkit@${PY_FLAVOR}
UJSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ujson>=5.10.0:devel/py-ujson@${PY_FLAVOR}

.include <bsd.port.mk>
