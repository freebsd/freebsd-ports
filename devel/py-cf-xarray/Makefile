PORTNAME=	cf-xarray
PORTVERSION=	0.10.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cf_xarray-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenience wrapper for using CF attributes on xarray objects
WWW=		https://cf-xarray.readthedocs.io/en/latest/ \
		https://github.com/xarray-contrib/cf-xarray

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2023.09.0:devel/py-xarray@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xarray>=2023.09.0:devel/py-xarray@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
