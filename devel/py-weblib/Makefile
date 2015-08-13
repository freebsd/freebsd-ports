# $FreeBSD$

PORTNAME=	weblib
PORTVERSION=	0.1.14
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Set of tools for web scraping projects

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytils>0:${PORTSDIR}/russian/py-pytils \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-extract:
	${RM} -rf ${WRKSRC}/test

.include <bsd.port.mk>
