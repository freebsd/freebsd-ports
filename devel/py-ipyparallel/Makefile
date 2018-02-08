# $FreeBSD$

PORTNAME=	ipyparallel
PORTVERSION=	6.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interactive Parallel Computing with IPython

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator@${FLAVOR} \
		${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook>=0:www/py-notebook@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=13:net/py-pyzmq@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.0:www/py-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.3:devel/py-traitlets@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
