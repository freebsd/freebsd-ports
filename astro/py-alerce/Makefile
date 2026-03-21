PORTNAME=	alerce
PORTVERSION=	2.3.0
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to interact with ALeRCE services and databases
WWW=		https://alerce.readthedocs.io/en/latest/index.html \
		https://github.com/alercebroker/alerce_client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=4.0.1:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.24.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
