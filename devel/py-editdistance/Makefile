PORTNAME=	editdistance
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast implementation of the edit distance (Levenshtein distance)
WWW=		https://github.com/roy-ht/editdistance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31200
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
