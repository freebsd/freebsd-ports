# $FreeBSD$

PORTNAME=	ipykernel
PORTVERSION=	4.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	IPython Kernel for Jupyter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.0:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.1.0:devel/py-traitlets

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
