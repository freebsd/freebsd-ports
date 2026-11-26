PORTNAME=	aws-sam-cli
PORTVERSION=	1.110.0
PORTREVISION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	adam.labuznik@gmail.com
COMMENT=	AWS Serverless Application Model CLI
WWW=		https://github.com/aws/aws-sam-cli \
		https://docs.aws.amazon.com/serverless-application-model/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aws-lambda-builders>0:devel/py-aws-lambda-builders@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aws-sam-translator>0:devel/py-aws-sam-translator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cfn-lint>0:devel/py-cfn-lint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chevron>0:textproc/py-chevron@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateparser>0:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>0:devel/py-watchdog@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
