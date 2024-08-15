PORTNAME=	proxmoxer
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Wrapper around the Proxmox REST API v2
WWW=		https://github.com/proxmoxer/proxmoxer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
