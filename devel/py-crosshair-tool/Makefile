PORTNAME=	crosshair-tool
PORTVERSION=	0.0.94
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	crosshair_tool-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyze Python code for correctness using symbolic execution
WWW=		https://crosshair.readthedocs.io/en/latest/ \
		https://github.com/pschanely/CrossHair

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.0.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygls>=1.0.0:devel/py-pygls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeshed-client>=2.0.5:devel/py-typeshed-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-inspect>=0.7.1:devel/py-typing-inspect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3-solver>=4.13.0.0:math/py-z3-solver@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
