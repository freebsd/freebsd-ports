PORTNAME=	glcontext
DISTVERSION=	3.1.0
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		display:test localbase python xorg
USE_PYTHON=	pep517 autoplist pytest
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	moderngl

TEST_ARGS=	--disable-plugin-autoload
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/glcontext/x11${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/glcontext/egl${PYTHON_TAG}.so

# tests as of 3.1.0: 2 passed in 557.26s

.include <bsd.port.mk>
