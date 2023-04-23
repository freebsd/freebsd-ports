PORTNAME=	apache-arrow
DISTVERSION=	8.0.0
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	APACHE/arrow/arrow-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Columnar in-memory analytics layer for big data
WWW=		https://arrow.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libarrow.so:databases/arrow # assumes that arrow is built with PYTHON=ON (python support is built)

USES=		compiler:c++11-lang pkgconfig python
USE_PYTHON=	distutils cython concurrent # autoplist is broken, see https://issues.apache.org/jira/browse/ARROW-16820

WRKSRC_SUBDIR=	python

MAKE_ENV=	FREEBSD_PYTHON_SUFFIX=${PYTHON_SUFFIX}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyarrow/*.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
