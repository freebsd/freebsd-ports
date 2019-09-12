# $FreeBSD$

PORTNAME=	pymisp
PORTVERSION=	2.4.114
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python library to access MISP platforms via their REST API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	python

USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
