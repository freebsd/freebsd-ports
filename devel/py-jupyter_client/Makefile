# $FreeBSD$

PORTNAME=	jupyter_client
PORTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Jupyter protocol implementation and client libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=13:net/py-pyzmq@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
