PORTNAME=	aws-sam-translator
DISTVERSION=	1.55.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nork@ninth-nine.com
COMMENT=	Library that transform SAM templates into AWS CloudFormation templates
WWW=		https://pypi.org/project/aws-sam-translator/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.19.5:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2<5:devel/py-jsonschema@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
