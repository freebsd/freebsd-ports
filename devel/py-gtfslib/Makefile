PORTNAME=	gtfslib
PORTVERSION=	1.0.0
CATEGORIES=	devel python databases geography
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library for reading GTFS-based transit data in Python

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy11>=0.6.1:databases/py-sqlalchemy11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtree>=0.24:devel/py-pyqtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyshp>=1.2.12:devel/py-pyshp@${PY_FLAVOR}

NO_ARCH=	yes

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
