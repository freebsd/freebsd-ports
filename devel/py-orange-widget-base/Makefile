# $FreeBSD$

PORTNAME=	orange-widget-base
DISTVERSION=	4.12.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base widget for Orange canvas

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}AnyQt>0:x11-toolkits/py-AnyQt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orange-canvas-core>=0.1.8a:devel/py-orange-canvas-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>0:graphics/py-pyqtgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.0:math/py-matplotlib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
