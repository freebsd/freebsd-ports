PORTNAME=	aws-lambda-builders
DISTVERSION=	1.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	nork@ninth-nine.com
COMMENT=	Python library to compile, build and package AWS Lambda functions
WWW=		https://pypi.org/project/aws-lambda-builders/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
