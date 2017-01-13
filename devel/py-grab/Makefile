# $FreeBSD$

PORTNAME=	grab
PORTVERSION=	0.6.32
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Site scraping framework

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl \
		${PYTHON_PKGNAMEPREFIX}weblib>0:devel/py-weblib \
		${PYTHON_PKGNAMEPREFIX}selection>0:devel/py-selection \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}user_agent>0:www/py-user_agent

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
