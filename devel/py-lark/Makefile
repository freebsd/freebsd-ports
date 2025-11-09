PORTNAME=	lark
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern parsing library
WWW=		https://github.com/lark-parser/lark

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	INTEREGULAR NEARLEY REGEX
OPTIONS_DEFAULT=INTEREGULAR REGEX
INTEREGULAR_DESC=	Check regex collisions
NEARLEY_DESC=		Import grammars from Nearley.js
REGEX_DESC=		Use third-party regex instead of standard library re

INTEREGULAR_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}interegular>=0.3.1<0.4.0:textproc/py-interegular@${PY_FLAVOR}
NEARLEY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Js2Py>=0:devel/py-Js2Py@${PY_FLAVOR}
REGEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR}

.include <bsd.port.mk>
