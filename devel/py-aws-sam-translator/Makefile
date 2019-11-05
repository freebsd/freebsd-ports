# $FreeBSD$

PORTNAME=	aws-sam-translator
PORTVERSION=	1.15.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nork@ninth-nine.com
COMMENT=	Library that transform SAM templates into AWS CloudFormation templates

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.5:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR} \
		${PY_ENUM34}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
