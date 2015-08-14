# $FreeBSD$

PORTNAME=	grab
PORTVERSION=	0.6.22
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Site scraping framework

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl \
		${PYTHON_PKGNAMEPREFIX}weblib>0:${PORTSDIR}/devel/py-weblib \
		${PYTHON_PKGNAMEPREFIX}selection>0:${PORTSDIR}/devel/py-selection

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
