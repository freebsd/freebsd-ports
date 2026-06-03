PORTNAME=	laszip
DISTVERSION=	0.3.0
CATEGORIES=	archivers
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bindings for LASzip made with pybind11
WWW=		https://laspy.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}pybind11>=3.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.7.1:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11.6:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	liblaszip.so:archivers/laszip

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	tmontaigu
GH_PROJECT=	laszip-python

.include <bsd.port.mk>
