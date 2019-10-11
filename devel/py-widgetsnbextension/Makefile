# $FreeBSD$

PORTNAME=	widgetsnbextension
PORTVERSION=	3.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	IPython HTML widgets for Jupyter

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notebook>=4.4.1:www/py-notebook@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
