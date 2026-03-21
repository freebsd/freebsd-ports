PORTNAME=	camel-converter
DISTVERSION=	5.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Converts string between snake case and snake case
WWW=		https://github.com/sanders41/camel-converter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 5.0.1:
# Results (0.19s):
#        130 passed
#          2 skipped

.include <bsd.port.mk>
