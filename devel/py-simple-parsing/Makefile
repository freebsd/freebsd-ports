PORTNAME=	simple-parsing
PORTVERSION=	0.1.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	simple_parsing-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small utility for simplifying and cleaning up argument parsing scripts
WWW=		https://github.com/lebrice/SimpleParsing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.15<1:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TOML YAML
OPTIONS_DEFAULT=TOML YAML

TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli>=2.2.1:textproc/py-tomli@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tomli-w>=1.0.0:textproc/py-tomli-w@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR}

.include <bsd.port.mk>
