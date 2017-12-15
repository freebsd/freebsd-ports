# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	streamparse
PORTVERSION=	3.5.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python analysis of Apache Storm streams

LICENSE=	APACHE20

USES=		python:2.7
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fabric3>0:devel/py-fabric3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pystorm>=3.1.0:devel/py-pystorm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thriftpy>=0.3.2:devel/py-thriftpy@${FLAVOR}

NO_ARCH=	YES

post-patch:
	${RM} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
