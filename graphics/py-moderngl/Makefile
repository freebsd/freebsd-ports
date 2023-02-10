PORTNAME=	moderngl
DISTVERSION=	5.7.4
CATEGORIES=	graphics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ModernGL: High performance rendering for Python 3
WWW=		https://moderngl.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}glcontext>=2.3.6<3:graphics/py-glcontext@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # testsuite SEGVs, see https://github.com/moderngl/moderngl/issues/547

USE_GITHUB=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/moderngl/mgl${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
