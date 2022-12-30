PORTNAME=	pint
PORTVERSION=	0.20.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pint-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Physical quantities module
WWW=		https://github.com/hgrecco/pint

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.8+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	pint/pint-convert

OPTIONS_DEFINE=	NUMPY UNCERTAINTIES
NUMPY_DESC=	Automatic conversion of units
UNCERTAINTIES_DESC=	Handle quantities with uncertainties

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.19.5,1:math/py-numpy@${PY_FLAVOR}
UNCERTAINTIES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.6:math/py-uncertainties@${PY_FLAVOR}

.include <bsd.port.mk>
