PORTNAME=	pyquil
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyQuil: Quantum programming in Python

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lark>=0.11.1:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.5:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcs-api-client>=0.8.1:devel/py-qcs-api-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry2>=0.9.2:devel/py-retry2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpcq>=3.6.0:devel/py-rpcq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.1:science/py-scipy@${PY_FLAVOR}

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.8+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
