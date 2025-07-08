PORTNAME=	Levenshtein
PORTVERSION=	0.25.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Fast computation of Levenshtein distance and string similarity
WWW=		https://github.com/maxbachmann/Levenshtein

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>=0.13:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rapidfuzz>0:devel/py-rapidfuzz@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Levenshtein/levenshtein*.so

.include <bsd.port.mk>
