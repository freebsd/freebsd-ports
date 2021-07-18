PORTNAME=	pyzipper
PORTVERSION=	0.3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmii@gmail.com
COMMENT=	Read and write AES encrypted zip files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR}

USES=		python:3.6+,run
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
