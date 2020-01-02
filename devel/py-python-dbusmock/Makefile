# $FreeBSD$

PORTNAME=	python-dbusmock
PORTVERSION=	0.18.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Mock D-Bus objects for tests

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
