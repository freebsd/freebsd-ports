# Created by: Martin Wilke

PORTNAME=	py3status
PORTVERSION=	3.45
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensible i3status wrapper written in python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GEVENT UDEV
GEVENT_DESC=	Gevent support
UDEV_DESC=	UDEV support

GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=1.1:devel/py-gevent@${PY_FLAVOR}
UDEV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyudev>=0.21.0:devel/py-pyudev@${PY_FLAVOR}

.include <bsd.port.mk>
