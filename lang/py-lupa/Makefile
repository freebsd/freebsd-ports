PORTNAME=	lupa
PORTVERSION=	2.5
CATEGORIES=	lang python
MASTER_SITES=	PYPI \
		https://github.com/scoder/lupa/releases/download/lupa-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper around Lua and LuaJIT
WWW=		https://github.com/scoder/lupa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		lua pkgconfig python
USE_PYTHON=	autoplist concurrent cython3 pep517 unittest

MAKE_ARGS=	--no-bundle --with-cython --with-lua-checks
TEST_ARGS=	lupa.tests.test

# Clean up bundled libraries
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/third-party \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} -r ${WRKSRC}/third-party/
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
