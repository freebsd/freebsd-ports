# $FreeBSD$

PORTNAME=	widgetsnbextension
PORTVERSION=	3.1.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	IPython HTML widgets for Jupyter

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notebook>=0:www/py-notebook@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
