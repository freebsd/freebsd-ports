# $FreeBSD$

PORTNAME=	ipyparallel
PORTVERSION=	6.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interactive Parallel Computing with IPython

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel \
		${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client \
		${PYTHON_PKGNAMEPREFIX}notebook>=0:www/py-notebook \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=13:net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.0:www/py-tornado

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
