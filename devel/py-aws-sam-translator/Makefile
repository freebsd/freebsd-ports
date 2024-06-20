PORTNAME=	aws-sam-translator
DISTVERSION=	1.89.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Library that transform SAM templates into AWS CloudFormation templates
WWW=		https://pypi.org/project/aws-sam-translator/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.19.5:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.8,1<3,1:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
