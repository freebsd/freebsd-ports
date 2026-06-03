PORTNAME=	pycayennelpp
PORTVERSION=	2.4.0
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	CayenneLPP decoder and encoder written in Python
WWW=		https://github.com/smlng/pycayennelpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} '/pytest-runner/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
