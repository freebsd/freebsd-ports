# $FreeBSD$

PORTNAME=	ipywidgets
PORTVERSION=	7.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Interactive HTML widgets for Jupyter notebooks and the IPython kernel

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.2.2:devel/py-ipykernel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>=1.2:devel/py-widgetsnbextension@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
