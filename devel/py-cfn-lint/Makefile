# $FreeBSD$

PORTNAME=	cfn-lint
PORTVERSION=	0.26.1
CATEGORIES=	devel python textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nork@ninth-nine.com
COMMENT=	AWS CloudFormation Linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aws-sam-translator>=1.15.1:devel/py-aws-sam-translator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0:devel/py-jsonschema@${PY_FLAVOR}
py27_RUN_DEPENDS= ${PYTHON_PKGNAMEPREFIX}pathlib2>=2.3.0:devel/py-pathlib2@${PY_FLAVOR}
py27_RUN_DEPENDS= ${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.0.2:devel/py-importlib-resources@${PY_FLAVOR}
py35_RUN_DEPENDS= ${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.0.2:devel/py-importlib-resources@${PY_FLAVOR}
py36_RUN_DEPENDS= ${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.0.2:devel/py-importlib-resources@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
