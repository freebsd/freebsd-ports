PORTNAME=	pnu-libpnu
DISTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hubert.tournier@gmail.com
COMMENT=	Common utility functions for the PNU project
WWW=		https://github.com/HubTou/libpnu

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist flavors pep517

SHEBANG_FILES=	src/libpnu/*.py

.include <bsd.port.mk>
