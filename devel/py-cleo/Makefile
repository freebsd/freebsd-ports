PORTNAME=	cleo
PORTVERSION=	1.0.0a5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create beautiful and testable command-line interfaces
WWW=		https://github.com/python-poetry/cleo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}crashtest>=0.4.0<0.5.0:devel/py-crashtest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylev>=1.3.0<2.0.0:devel/py-pylev@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
