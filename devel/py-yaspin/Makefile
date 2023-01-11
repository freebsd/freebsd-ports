PORTNAME=	yaspin
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet Another Terminal Spinner
WWW=		https://github.com/pavdmyt/yaspin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor-whl>=1.1.2:devel/py-termcolor-whl@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
