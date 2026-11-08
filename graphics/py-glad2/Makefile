PORTNAME=	glad2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.8
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-Language Vulkan/GL/GLES/EGL/GLX/WGL loader-generator
WWW=		https://glad.dav1d.de/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2@${PY_FLAVOR}
TEST_DEPENDS=	cmake:devel/cmake-core \
		glfw>0:graphics/glfw

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Dav1dde
GH_PROJECT=	glad

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test: # build test project using Glad2
	@cd ${WRKSRC} && \
		${MKDIR} test-project && \
		cd test-project && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m glad --api="gl:core=3.3" --out-path=glad_output c && \
		${CP} ${FILESDIR}/main.cpp glad_output/src && \
		${CP} ${FILESDIR}/CMakeLists.txt glad_output && \
		${MKDIR} build && \
		cd build && \
		cmake ../glad_output && \
		${MAKE_CMD}

.include <bsd.port.mk>
