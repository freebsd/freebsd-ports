PORTNAME=	llfuse
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	filesystems devel python
MASTER_SITES=	PYPI \
		https://github.com/python-llfuse/python-llfuse/releases/download/release-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for the low-level FUSE API
WWW=		https://github.com/python-llfuse/python-llfuse

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

LIB_DEPENDS=	libfuse.so:filesystems/fusefs-libs

USES=		compiler:c++11-lang fuse pkgconfig python
USE_PYTHON=	autoplist concurrent cython3 pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
