# $FreeBSD$

PORTNAME=	ipykernel
PORTVERSION=	4.10.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	IPython Kernel for Jupyter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython5>=4.0.0:devel/ipython5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.1.0:devel/py-traitlets@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
