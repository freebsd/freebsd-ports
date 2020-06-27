# $FreeBSD$

PORTNAME=	pygeoapi
PORTVERSION=		0.8.0
CATEGORIES=	graphics geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	OGC API server implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>0:devel/py-unicodecsv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
