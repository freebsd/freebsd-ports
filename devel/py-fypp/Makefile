PORTNAME=	fypp
DISTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # missing files needed for tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python powered preprocessor
WWW=		https://github.com/aradi/fypp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aradi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

.include <bsd.port.mk>
