PORTNAME=	pyqtgraph
DISTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	graphics science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific graphics and GUI library for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
