PORTNAME=	astropy-iers-data
DISTVERSION=	0.2025.10.20.0.39.8
CATEGORIES=	astro
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	astropy_iers_data-${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	IERS Earth Rotation and Leap Second tables for the astropy
WWW=		https://github.com/astropy/astropy-iers-data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
