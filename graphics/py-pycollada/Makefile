PORTNAME=	pycollada
DISTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Python library for reading and writing collada documents

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.0:devel/py-dateutil@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	LXML

LXML_DESC=		Uses lxml for XML loading, construction, and saving.
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
