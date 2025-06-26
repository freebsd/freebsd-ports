PORTNAME=	pyyaml-ft
PORTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyyaml_ft-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	YAML parser and emitter for Python with support for free-threading
WWW=		https://pyyaml.org/wiki/PyYAMLDocumentation \
		https://github.com/Quansight-Labs/pyyaml-ft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		localbase python
USE_PYTHON=	autoplist concurrent cython3 pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
