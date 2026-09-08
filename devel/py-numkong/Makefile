PORTNAME=	numkong # successor of simsimd
DISTVERSION=	7.8.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable mixed-precision math, linear-algebra, & retrieval library
WWW=		https://ashvardanian.com/posts/numkong/ \
		https://github.com/ashvardanian/NumKong

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 7.8.2:
# Results (506.04s (0:08:26)):
#     240080 passed
#     21322 skipped

.include <bsd.port.mk>
