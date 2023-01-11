PORTNAME=	robotframework-pabot
PORTVERSION=	2.8.0
CATEGORIES=	devel www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel test runner for Robot Framework
WWW=		https://pabot.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}natsort>=8.2.0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework>=3.2:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-stacktrace>=0.4.1:devel/py-robotframework-stacktrace@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
