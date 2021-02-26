# $FreeBSD$

PORTNAME=	zstandard
DISTVERSION=	0.15.1
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Zstandard bindings for Python, a full-featured version

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_11_powerpc64=	fails to build: cffi.error.CDefError: parse error
BROKEN_FreeBSD_12_powerpc64=	fails to build: cffi.error.CDefError: parse error

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		localbase python:3.6+
USE_PYTHON=	distutils autoplist
#PYDISTUTILS_BUILDARGS=	--system-zstd # breaks in runtime due to version mismatch, keep disabled until this is fixed: https://github.com/indygreg/python-zstandard/issues/132

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zstandard && ${STRIP_CMD} backend_c*.so _cffi*.so

do-test: # runs the internal testsuite, tests are unreliable or faulty: https://github.com/indygreg/python-zstandard/issues/133
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILDARGS} test

.include <bsd.port.mk>
