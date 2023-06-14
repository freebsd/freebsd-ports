PORTNAME=	lupa
PORTVERSION=	2.0
CATEGORIES=	lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper around Lua and LuaJIT
WWW=		https://github.com/scoder/lupa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		lua pkgconfig python
USE_PYTHON=	autoplist concurrent cython distutils unittest

MAKE_ARGS=	--no-bundle --with-cython --with-lua-checks
TEST_ARGS=	lupa.tests.test

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third-party/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
