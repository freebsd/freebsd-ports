PORTNAME=	importlib-metadata
DISTVERSION=	6.11.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	6
DISTNAME=	importlib_metadata-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Read metadata from Python packages
WWW=		https://github.com/python/importlib_metadata

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zipp>=0.5:devel/py-zipp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
