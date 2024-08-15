PORTNAME=	glcontext
DISTVERSION=	3.0.0
CATEGORIES=	graphics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable OpenGL context for Python
WWW=		https://github.com/moderngl/glcontext

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		localbase python xorg
USE_PYTHON=	pep517 autoplist pytest # tests fail, see https://github.com/moderngl/glcontext/issues/36
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	moderngl

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/glcontext/x11${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/glcontext/egl${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
