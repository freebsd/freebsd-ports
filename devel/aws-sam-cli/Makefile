PORTNAME=	aws-sam-cli
PORTVERSION=	1.110.0
PORTREVISION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	adam.labuznik@gmail.com
COMMENT=	The AWS Serverless Application Model CLI
WWW=		https://github.com/aws/aws-sam-cli \
		https://docs.aws.amazon.com/serverless-application-model/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS = ${PYTHON_PKGNAMEPREFIX}chevron>0:textproc/py-chevron@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}click flask boto3>0:www/py-boto3@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}cookiecutter docker dateparser>0:devel/py-dateparser@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}watchdog>0:devel/py-watchdog@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}tomlkit>0:textproc/py-tomlkit@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}translator>0:devel/py-aws-sam-translator@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-ruamel.yaml@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}builders>0:devel/py-aws-lambda-builders@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}extensions>0:devel/py-typing-extensions@${PY_FLAVOUR} \
${PYTHON_PKGNAMEPREFIX}lint>0:devel/py-cfn-lint@${PY_FLAVOUR} \

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

CPE_VENDOR=	python

.include <bsd.port.mk>
