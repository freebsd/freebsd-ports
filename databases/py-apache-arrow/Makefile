PORTNAME=	apache-arrow
DISTVERSION=	20.0.0
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
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libarrow.so:databases/arrow # assumes that arrow is built with PYTHON=ON (python support is built)

USES=		compiler:c++11-lang pkgconfig python shebangfix
USE_PYTHON=	distutils cython3 # autoplist is broken, see https://issues.apache.org/jira/browse/ARROW-16820

WRKSRC_SUBDIR=	python

SHEBANG_FILES=	cmake_modules/aws_sdk_cpp_generate_variables.sh

MAKE_ENV=	FREEBSD_PYTHON_SUFFIX=${PYTHON_SUFFIX}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyarrow/*.cpython-${PYTHON_SUFFIX}.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyarrow/libarrow_python.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyarrow/libarrow_python_flight.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyarrow/libarrow_python_parquet_encryption.so

.include <bsd.port.mk>
