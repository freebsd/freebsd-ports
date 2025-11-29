PORTNAME=	srsly
PORTVERSION=	2.5.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/explosion/srsly/releases/download/release-v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern high-performance serialization utilities for Python
WWW=		https://github.com/explosion/srsly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}catalogue>=2.0.3<2.1.0:devel/py-catalogue@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
