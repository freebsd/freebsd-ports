PORTNAME=	sqlglot-mypy
PORTVERSION=	1.20.0.post3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sqlglot_mypy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional static typing for SQLGlot
WWW=		https://github.com/VaggelisD/sqlglot-mypy

LICENSE=	MIT PSFL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}librt>=0.8.0:devel/py-librt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=1.0.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=1.0.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}types-psutil>=0:devel/py-types-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-setuptools>=0:devel/py-types-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}librt>=0.8.0:devel/py-librt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=1.0.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=1.0.0:devel/py-pathspec@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	py*-mypy

OPTIONS_DEFINE=	NATIVE_PARSER
OPTIONS_DEFAULT=NATIVE_PARSER
NATIVE_PARSER_DESC=	Native binary format parser

NATIVE_PARSER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ast-serialize>=0.1.1<1.0.0:devel/py-ast-serialize@${PY_FLAVOR}

.include <bsd.port.mk>
