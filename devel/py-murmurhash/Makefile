PORTNAME=	murmurhash
DISTVERSION=	1.0.10
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython bindings for MurmurHash2
WWW=		https://github.com/explosion/murmurhash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/murmurhash/tests

pre-test: # tests fail to run with __init__.py: they can't find the murmurhash module
	@${RM} ${TEST_WRKSRC}/__init__.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/murmurhash/mrmr*.so

.include <bsd.port.mk>
