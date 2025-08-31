PORTNAME=	pyquil
DISTVERSION=	4.6.1
PORTREVISION=	5
CATEGORIES=	devel python # quantum-computing
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyQuil: Quantum programming in Python
WWW=		https://github.com/rigetti/pyquil

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark>=0.11.1:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.5:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.10.7:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcs-sdk-python>=0.16.3:devel/py-qcs-sdk-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry2>=0.9.2,<0.10.0:devel/py-retry2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpcq>=3.10.0<4.0.0:devel/py-rpcq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.3,1<2.0.0,1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity8>=8.2.2<9.0.0:devel/py-tenacity8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-python-dateutil>=2.8.19:devel/py-types-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-retry>=0.9.9<1.0.0:devel/py-types-retry@${PY_FLAVOR} \
		quilc:lang/quilc

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
