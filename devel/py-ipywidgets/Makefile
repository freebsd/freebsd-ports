# $FreeBSD$

PORTNAME=	ipywidgets
PORTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Interactive HTML widgets for Jupyter notebooks and the IPython kernel

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=4.0.0:devel/ipython \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.2.2:devel/py-ipykernel \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>=1.2:devel/py-widgetsnbextension \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
