PORTNAME=	lupa
PORTVERSION=	2.1
CATEGORIES=	lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper around Lua and LuaJIT
WWW=		https://github.com/scoder/lupa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>=3.0.9:lang/cython3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		lua pkgconfig python
USE_PYTHON=	autoplist concurrent pep517 unittest

MAKE_ARGS=	--no-bundle --with-cython --with-lua-checks
TEST_ARGS=	lupa.tests.test

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third-party/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
