PORTNAME=	azure-data-tables
DISTVERSION=	12.4.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Data Tables Client Library for Python
WWW=		https://pypi.org/project/azure-data-tables/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.24.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.0<2.0:www/py-yarl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6.1<1.0.0:devel/py-isodate@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
