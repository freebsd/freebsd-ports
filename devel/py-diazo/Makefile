# $FreeBSD$

PORTNAME=	diazo
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Implements a Deliverance like language using a pure XSLT engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}experimental.cssselect>0:${PORTSDIR}/devel/py-experimental.cssselect \
		${PYTHON_PKGNAMEPREFIX}future>0:${PORTSDIR}/devel/py-future \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:${PORTSDIR}/devel/py-repoze.xmliter \
		${PYTHON_PKGNAMEPREFIX}webob>=0:${PORTSDIR}/www/py-webob

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
