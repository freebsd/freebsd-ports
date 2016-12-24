# Created by: vanilla@
# $FreeBSD$

PORTNAME=	google-apputils
PORTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google Application Utilities for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gflags>2:devel/py-gflags \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}dateutil>2:devel/py-dateutil

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
