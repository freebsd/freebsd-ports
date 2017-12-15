# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonref
PORTVERSION=	0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Implementation of JSON Reference for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests@${FLAVOR}

USES?=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
