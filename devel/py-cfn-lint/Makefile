PORTNAME=	cfn-lint
DISTVERSION=	0.54.2
CATEGORIES=	devel python textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nork@ninth-nine.com
COMMENT=	AWS CloudFormation Linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aws-sam-translator>=1.38.0:devel/py-aws-sam-translator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.9:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>5.4:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6-3.9
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
