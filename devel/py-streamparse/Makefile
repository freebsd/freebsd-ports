# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	streamparse
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python analysis of Apache Storm streams

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fabric3>0:devel/py-fabric3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pystorm>0:devel/py-pystorm

NO_ARCH=	YES

post-patch:
	${RM} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
