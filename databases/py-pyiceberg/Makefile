PORTNAME=	pyiceberg
DISTVERSION=	0.11.1
CATEGORIES=	databases python # dataset access library - close enough to 'databases'
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to access Apache Iceberg datasets
WWW=		https://py.iceberg.apache.org/ \
		https://github.com/apache/iceberg-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=5.5:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.1.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mmh3>=4.0.0:devel/py-mmh3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.1.0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroaring>=1.0.0:devel/py-pyroaring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=10.11.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strictyaml>=1.7.0:devel/py-strictyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.2.3:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.13.0:archivers/py-zstandard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist

.include <bsd.port.mk>
