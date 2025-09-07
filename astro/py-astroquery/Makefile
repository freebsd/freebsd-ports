PORTNAME=	astroquery
PORTVERSION=	0.4.10
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functions and classes to access online astronomical data resources
WWW=		https://astroquery.readthedocs.io/en/latest/ \
		https://github.com/astropy/astroquery

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=5.0:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=15.0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvo>=1.5:astro/py-pyvo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-astropy>0:astro/py-pytest-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=0.13:devel/py-pytest-doctestplus@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>0:devel/py-moto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-dependency>0:devel/py-pytest-dependency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# tests as of 0.4.10: 6 failed, 1701 passed, 744 skipped, 2 xfailed, 4 errors in 90.35s (0:01:30)

.include <bsd.port.mk>
