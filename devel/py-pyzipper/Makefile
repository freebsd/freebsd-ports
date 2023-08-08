PORTNAME=	pyzipper
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmii@gmail.com
COMMENT=	Read and write AES encrypted zip files
WWW=		https://github.com/danifus/pyzipper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR}

USES=		python:run
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/test/badsyntax_*.py
	@${RM} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
