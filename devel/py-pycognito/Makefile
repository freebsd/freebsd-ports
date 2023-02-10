PORTNAME=	pycognito
DISTVERSION=	2022.11.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Makes working with AWS Cognito easier for Python developers
WWW=		https://github.com/pvizeli/pycognito

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envs>0:devel/py-envs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jose>0:security/py-python-jose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
