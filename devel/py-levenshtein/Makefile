PORTNAME=	levenshtein
DISTVERSION=	0.27.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@wener.org
COMMENT=	Fast computation of Levenshtein distance and string similarity
WWW=		https://github.com/rapidfuzz/Levenshtein

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.9.0:devel/py-rapidfuzz@${PY_FLAVOR}

USES=		cmake:indirect python:3.11+
USE_PYTHON=	autoplist cython pep517 pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Levenshtein/${PORTNAME}_cpp${PYTHON_TAG}.so

.include <bsd.port.mk>
