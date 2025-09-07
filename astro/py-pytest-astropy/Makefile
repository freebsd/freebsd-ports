PORTNAME=	pytest-astropy
PORTVERSION=	0.11.0
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Meta-package containing dependencies for testing
WWW=		https://github.com/astropy/pytest-astropy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=5.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-arraydiff>=0.5:devel/py-pytest-arraydiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-astropy-header>=0.2.2:astro/py-pytest-astropy-header@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.3.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=1.0.0:devel/py-pytest-doctestplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-filter-subpackage>=0.1.2:devel/py-pytest-filter-subpackage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=2.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-remotedata>=0.4.1:devel/py-pytest-remotedata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.6:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
