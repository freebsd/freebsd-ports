# $FreeBSD$

PORTNAME=	diazo
PORTVERSION=	1.2.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Deliverance like language using a pure XSLT engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:devel/py-repoze.xmliter \
		${PYTHON_PKGNAMEPREFIX}webob>=0:www/py-webob

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
