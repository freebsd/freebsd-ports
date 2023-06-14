PORTNAME=	opster
DISTVERSION=	5.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line parsing speedster
WWW=		https://github.com/piranha/opster/

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/piranha/opster/issues/62

USE_GITHUB=	yes
GH_ACCOUNT=	piranha

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
