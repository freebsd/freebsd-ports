PORTNAME=	itypes
DISTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Simple immutable types for Python
WWW=		https://github.com/PavanTatikonda/itypes

LICENSE=	BSD2CLAUSE

DEPRECATED=	Upstream archived repository and suggest using devel/py-pyrsistent instead
EXPIRATION_DATE=2025-06-30

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
