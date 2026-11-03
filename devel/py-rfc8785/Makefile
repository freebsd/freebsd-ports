PORTNAME=	rfc8785
DISTVERSION=	0.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure-Python implementation of RFC 8785 (JSON Canonicalization Scheme)
WWW=		https://trailofbits.github.io/rfc8785.py/ \
		https://github.com/trailofbits/rfc8785.py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.5:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.1.4: 42 passed, 1 skipped

.include <bsd.port.mk>
