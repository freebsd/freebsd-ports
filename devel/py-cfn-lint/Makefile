PORTNAME=	cfn-lint
DISTVERSION=	0.87.6
PORTREVISION=	1
CATEGORIES=	devel python textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONFULL}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	AWS CloudFormation Linter
WWW=		https://pypi.org/project/cfn-lint/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aws-sam-translator>=1.89.0:devel/py-aws-sam-translator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jschema-to-python>=1.2.3:devel/py-jschema-to-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.9:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4,2<4,2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2021.7.1:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sarif-om>=1.0.4:devel/py-sarif-om@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.0.0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>5.4:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest
TEST_ENV=	${MAKE_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
