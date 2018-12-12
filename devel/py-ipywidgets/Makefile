# $FreeBSD$

PORTNAME=	ipywidgets
PORTVERSION=	7.4.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Interactive HTML widgets for Jupyter notebooks and the IPython kernel

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython5>=4.0.0:devel/ipython5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.2.2:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>=1.2:devel/py-widgetsnbextension@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
